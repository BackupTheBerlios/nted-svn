
#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "tcpconnection.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "tcpconnection.h"


wxCriticalSection m_critsec;

TCPThread::TCPThread(wxTextInputStream *Input,wxArrayString *MsgList):wxThread()
{
  m_input=Input;
  m_msglist=MsgList;
}

void *TCPThread::Entry()
{
  wxString msg;
  
//::wxSafeShowMessage(_("Titanes"),_("Dentro del Thread."));
  while (TestDestroy()==FALSE)
  {
    msg=m_input->ReadLine();
    m_critsec.Enter();
    m_msglist->Add(msg);
    m_critsec.Leave();
  }
	::wxSafeShowMessage(_("Titanes"),_("Fuera del Thread."));
  return NULL;
}

TCPConnection::TCPConnection()
{
  Conn=new wxSocketClient(wxSOCKET_WAITALL);
  sockinstrm=new wxSocketInputStream(*Conn);
  Input=new wxTextInputStream(*sockinstrm);
//  Input=new wxTextInputStream(*(new wxSocketInputStream(*Conn)));
  sockoutstrm=new wxSocketOutputStream(*Conn);
  Output=new wxTextOutputStream(*sockoutstrm,wxEOL_UNIX);
//  Output=new wxTextOutputStream(*(new wxSocketOutputStream(*Conn)));
  MsgList=new wxArrayString();
///  ::wxLogError(_("Antes de Crear el Thread"));
  ListenThread=new TCPThread(Input,MsgList);
///  ::wxLogError(_("Antes de Thread.Create"));
  switch (wxThreadError error=ListenThread->Create())
  {
    case wxTHREAD_NO_RESOURCE:
    {
      ::wxLogFatalError(_("Error al crear el hilo de la conexión.\nNo hay suficientes recursos."));
      break;
    }
    case wxTHREAD_RUNNING:
    {
      ::wxLogError(_("Error al crear el hilo de la conexión.\nEl hilo ya está ejecutándose."));
      break;
    }
    default:
    {
      if (error!=wxTHREAD_NO_ERROR)
      {
        ::wxLogError(_("Error desconocido(%d) al crear el hilo de la conexión.\n"),error);
      }
    }
  }
///  ::wxLogError(_("Despues de Thread.Create"));
}

void TCPConnection::Connect()
{
  bool reconnect=TRUE;

  address=new wxIPV4address();
  if ((address->Hostname(_T(TEDHOST))==FALSE) || (address->Service(TEDPORT)==FALSE))
  {
    ::wxLogFatalError(_("Error al crear el socket de conexión.\n;"));
  }
  Conn->Connect(*address,FALSE);
  while (Conn->WaitOnConnect(CONNECTTIMEOUT)==FALSE)
  {
    // ESTO HAY QUE SACARLO DE AQUI Y LLEVARLO AL INTERFAZ DE USUARIO
    if (::wxMessageBox(_("Tiempo de espera agotado al conectar al servidor.\n¿Reintentar conexión?"),_("Titanes"),wxYES_NO|wxICON_ERROR)!=wxYES)
    {
      break;
    }
  }
//::wxSafeShowMessage(_("Titanes"),_("Fuera del While"));
  if (Conn->IsConnected()==TRUE)
  {
//::wxSafeShowMessage(_("Titanes"),_("Connectado"));
    ListenThread->Run();
  }
  else
  {
    // ESTO HAY QUE MODIFICARLO
::wxSafeShowMessage(_("Titanes"),_("NO Conectado"));
  }
  return;
}

void TCPConnection::SendMessage(wxString Msg)
{
	Output->WriteString(Msg);
}

wxString TCPConnection::GetMessage()
{
  wxString msg;

  m_critsec.Enter();
  if (MsgList->GetCount()>0)
  {
    msg=MsgList->Item(0);
    MsgList->RemoveAt(0);
  }
  else
  {
    msg=wxEmptyString;
  }
  m_critsec.Leave();
  return msg;
}

wxString TCPConnection::WaitMessage()
{
  wxString msg;

  while ((msg=GetMessage())==wxEmptyString)
  {
    ::wxSafeYield();
    ::wxUsleep(100);
  }
  return msg;
}

void TCPConnection::Disconnect()
{
  is (ListenThread->IsAlive()==TRUE)
  {
    ListenThread->Delete();
  }
  Conn->Close();
  return;
}

bool TCPConnection::IsConnected()
{
  return Conn->IsConnected();
}

