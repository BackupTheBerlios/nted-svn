
#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "tedprotocol.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "tedprotocol.h"

TEDProtocol::TEDProtocol()
{
  TCPConn=new TCPConnection();
}

void TEDProtocol::Connect()
{
  TCPConn->Connect();
}

void TEDProtocol::Login(wxString UserName,wxString UserPass)
{
  wxString sndmsg;
  wxString rcvmsg;
  wxStringTokenizer rcvtok;
  wxString tok;
  long int longvalue;
  struct TEDChatRoom *room;
  
  sndmsg=_T("TC 0.1a/r0228\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok=wxStringTokenizer(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
  }
  tok=rcvtok.GetNextToken();
  if (tok==_T("NO"))
  {
    tok=rcvtok.GetNextToken();
    if (tok==_T("1"))
    {
      ::wxSafeShowMessage(_("Titanes"),_("La version del cliente es incorrecta.\nVisite la web para obtener la ultima version."));
    }
    else if (tok==_T("2"))
    {
      ::wxSafeShowMessage(_("Titanes"),_("El servidor está demasiado ocupado.\nInténtelo de nuevo más tarde."));
    }
    else
    {
      ::wxSafeShowMessage(_("Titanes"),_("El servidor ha respondido con un comando de error desconocido."));
    }
  }
  else if (tok==_T("OK"))
  {
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_("El servidor ha respondido con un comando desconocido."));
  }
  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  sndmsg=_T("UL ")+UserName+_T(" ")+UserPass+_T("\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok.SetString(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
  }
//  ::wxSafeShowMessage(_("Titanes"),wxString::Format("%d",rcvtok.CountTokens()));
  tok=rcvtok.GetNextToken();
//  ::wxSafeShowMessage(_("Titanes"),wxString::Format("%d",rcvtok.CountTokens()));
  if (tok==_T("NO"))
  {
    ::wxSafeShowMessage(_("Titanes"),_("Login incorrecto."));
  }
  else if (tok==_("OK"))
  {
    if (rcvtok.CountTokens()==6)
    {
      User.Name=UserName;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      User.Wins=longvalue;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      User.Looses=longvalue;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      User.Retired=longvalue;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      User.Gold=longvalue;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      User.DeckValue=longvalue;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      User.Rank=longvalue;
    }
    else
    {
      ::wxSafeShowMessage(_("Titanes"),_("El servidor ha respondido con un comando desconocido."));
    }
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_("El servidor ha respondido con un comando de error desconocido."));
  }
  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  sndmsg=_T("UP TimeStamp\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok.SetString(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
  }
  tok=rcvtok.GetNextToken();
  if (tok!=_T("OK"))
  {
    ::wxSafeShowMessage(_("Titanes"),_("Error recibiendo nuevas cartas."));
  }
  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  sndmsg=_T("CR\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok.SetString(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
  }
  tok=rcvtok.GetNextToken();
  if (tok!=_T("OK"))
  {
    ::wxSafeShowMessage(_("Titanes"),_("Error recibiendo nuevas cartas."));
  }
  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  do
  {
    rcvmsg=TCPConn->WaitMessage();
    rcvtok.SetString(rcvmsg);
    if (rcvtok.HasMoreTokens()==FALSE)
    {
      ::wxLogFatalError(_("Error en la respuesta del servidor."));
    }
    tok=rcvtok.GetNextToken();
    if (tok==_T("CR"))
    {
      room=new struct TEDChatRoom;
      tok=rcvtok.GetNextToken();
      tok.ToLong(&longvalue);
      room->RoomId=longvalue;
      tok=rcvtok.GetString();
      room->RoomName=tok;
      User.Rooms.Add(room);
      // DESCOMENTAR ESTA LINEA SI HAY ALGUNA POSIBILIDAD DE QUE ALGUIEN
      // CREE O PUEDA CREAR UNA SALA DE NOMBRE "OK"
//      tok=_T("CR");
    }
    else if (tok!=_T("OK"))
    {
      ::wxSafeShowMessage(_("Titanes"),_("Error recibiendo salas de chat."));
    }
    ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  } while (tok!=_T("OK"));
  User.Room=0;
}

wxString TEDProtocol::GetMessage()
{
  wxString msg;

  msg=TCPConn->GetMessage();
  return msg;
}

wxString TEDProtocol::WaitMessage()
{
  wxString msg;

  msg=TCPConn->WaitMessage();
  return msg;
}

void TEDProtocol::Disconnect()
{
  TCPConn->Disconnect();
  return;
}

bool TEDProtocol::IsConnected()
{
  return TCPConn->IsConnected();
}
