
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
//	::wxSafeShowMessage(_("Titanes"),_("Fuera del Thread."));
  return NULL;
}

TCPConnection::TCPConnection(wxEvtHandler& handler, int id = -1)
{
//  Conn=new wxSocketClient(wxSOCKET_WAITALL);
  Conn=new wxSocketClient(wxSOCKET_BLOCK);
//  Conn=new wxSocketClient(wxSOCKET_NOWAIT);
  // Setup the event handler and subscribe to most events
  Conn->SetEventHandler(handler, id);
  Conn->SetNotify(wxSOCKET_LOST_FLAG);
  Conn->Notify(true);
  sockinstrm=new wxSocketInputStream(*Conn);
  Input=new wxTextInputStream(*sockinstrm);
//  Input=new wxTextInputStream(*(new wxSocketInputStream(*Conn)));
  sockoutstrm=new wxSocketOutputStream(*Conn);
  Output=new wxTextOutputStream(*sockoutstrm,wxEOL_UNIX);
//  Output=new wxTextOutputStream(*(new wxSocketOutputStream(*Conn)));
  MsgList=new wxArrayString();
///  ::wxLogError(_("Antes de Crear el Thread"));

//#if 0

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

//#endif

///  ::wxLogError(_("Despues de Thread.Create"));
}

void TCPConnection::Connect()
{
#if 0
  bool reconnect=TRUE;
#endif
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

//#if 0
    ListenThread->Run();
//#endif

  }
  else
  {
    // ESTO HAY QUE MODIFICARLO
//::wxSafeShowMessage(_("Titanes"),_("NO Conectado"));
  }
  return;
}

void TCPConnection::SendMessage(wxString Msg)
{
	Output->WriteString(Msg);
}

void TCPConnection::GetSocketData()
{
  wxString msg;

//::wxSafeShowMessage(_("Titanes"),_("Dentro de GetSocketData"));
  Conn->SetNotify(wxSOCKET_LOST_FLAG);
  while (Conn->WaitForRead(0,100)==true)
  {
//::wxSafeShowMessage(_("Titanes"),_("Antes del ReadLine"));
    msg=Input->ReadLine();
//::wxSafeShowMessage(_("Titanes"),_("Antes del Enter"));
    m_critsec.Enter();
//::wxSafeShowMessage(_("Titanes"),_("Antes del Add"));
    MsgList->Add(msg);
//::wxSafeShowMessage(_("Titanes"),_("Antes del Leave"));
    m_critsec.Leave();
//::wxSafeShowMessage(_("Titanes"),_("Despues del Leave"));
/*
    ::wxSafeYield();
    ::wxMilliSleep(300);
*/
  }
  Conn->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
//::wxSafeShowMessage(_("Titanes"),_("Dentro de GetSocketData"));
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
    ::wxMilliSleep(100);
  }
  return msg;
}

void TCPConnection::Disconnect()
{
  if (ListenThread->IsAlive()==TRUE)
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

