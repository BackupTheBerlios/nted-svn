
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
  m_logged=FALSE;
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

  // VERIFICAMOS QUE NUESTRA VERSION DEL CLIENTE ES VALIDA
  sndmsg=_T("TC 0.1a/r0228\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok=wxStringTokenizer(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
    return;
  }
  tok=rcvtok.GetNextToken();
  if (tok==_T("OK"))
  {
  }
  else if (tok==_T("NO"))
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
    return;
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_("El servidor ha respondido con un comando desconocido."));
    return;
  }
//  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  // SI LA VERSION ES CORRECTA INTENTAMOS ENTRAR AL SERVIDOR
  sndmsg=_T("UL ")+UserName+_T(" ")+UserPass+_T("\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok.SetString(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
    return;
  }
//  ::wxSafeShowMessage(_("Titanes"),wxString::Format("%d",rcvtok.CountTokens()));
  tok=rcvtok.GetNextToken();
//  ::wxSafeShowMessage(_("Titanes"),wxString::Format("%d",rcvtok.CountTokens()));
  if (tok==_("OK"))
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
      return;
    }
  }
  else if (tok==_T("NO"))
  {
    ::wxSafeShowMessage(_("Titanes"),_("Login incorrecto."));
    return;
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_("El servidor ha respondido con un comando de error desconocido."));
    return;
  }
//  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  // ESTA PARTE DE AQUI PARECE NO ESTAR BIEN EN EL CLIENTE-SERVIDOR
  // PORQUE SE SUPONE QUE LE ENVIAMOS NUESTRA ULTIMA ACTUALIZACION
  // Y EL NOS RESPONDE CON LA LISTA DE SERVIDORES QUE CONTIENEN
  // LAS NUEVAS CARTAS O LAS ACTUALIZACIONES A LAS EXISTENTES Y
  // LUEGO CON LA LISTA DE LOS IDENTIFICADORES DE LAS CARTAS.
  // FINALMENTE ENVIA UN "OK" DONDE, SI HEMOS RECIBIDO ALGUNA ACTUALIZACION
  // DETRAS IRA SEGUIDO POR EL NUEVO TIMESTAMP Y SE CERRARA LA CONEXION,
  // Y EN CASO CONTRARIO NO HABRA NINGUN NUEVO TIMESTAMP Y LA CONEXION SEGUIRA
  sndmsg=_T("UP TimeStamp\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  rcvtok.SetString(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
    return;
  }
  tok=rcvtok.GetNextToken();
  if (tok!=_T("OK"))
  {
    ::wxSafeShowMessage(_("Titanes"),_("Error recibiendo nuevas cartas."));
    return;
  }
//  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  // SI TODO HA IDO BIEN OBTENEMOS EL NOMBRE DE LAS SALAS
  sndmsg=_T("CR\n");
  TCPConn->SendMessage(sndmsg);
/*
  rcvmsg=TCPConn->WaitMessage();
  rcvtok.SetString(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
  }
  tok=rcvtok.GetNextToken();
  // ESTE CHEQUEO ESTA MAL PORQUE DEBERIA DE SER UN "CR"
  if (tok!=_T("CR"))
  {
    ::wxSafeShowMessage(_("Titanes"),_("Error recibiendo las salas. Se recibió ")+rcvmsg);
  }
*/
  bool rcvone=FALSE;
  do
  {
    rcvmsg=TCPConn->WaitMessage();
    rcvtok.SetString(rcvmsg);
    if (rcvtok.HasMoreTokens()==FALSE)
    {
      ::wxLogFatalError(_("Error en la respuesta del servidor."));
      return;
    }
    tok=rcvtok.GetNextToken();
    if (tok==_T("CR"))
    {
      rcvone=TRUE;
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
    else if ((tok!=_T("OK")) || (rcvone==FALSE))
    {
      ::wxSafeShowMessage(_("Titanes"),_("Error recibiendo salas de chat."));
      return;
    }
//    ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  } while (tok!=_T("OK"));
  User.Room=0;
  m_logged=TRUE;
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

void TEDProtocol::SendMessage(wxString msg)
{
  TCPConn->SendMessage(msg);
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

bool TEDProtocol::IsLogged()
{
  return m_logged;
}

wxInt32 TEDProtocol::GetNumChatRooms()
{
  if ((IsConnected()==TRUE) && (IsLogged()==TRUE))
  {
    return User.Rooms.GetCount();
  }
  return -1;
}

struct TEDChatRoom *TEDProtocol::GetChatRoom(wxInt32 roomindex)
{
  if ((roomindex<0) || (roomindex>GetNumChatRooms()))
  {
    return NULL;
  }
  return User.Rooms[roomindex];
}

wxString TEDProtocol::GetChatRoomName(wxInt32 roomindex)
{

  if ((roomindex<0) || (roomindex>GetNumChatRooms()))
  {
    return wxEmptyString;
  }
  return User.Rooms[roomindex]->RoomName;
}

bool TEDProtocol::ChatEnter(wxInt32 roomindex)
{
  wxString sndmsg;
  wxString rcvmsg;
  wxStringTokenizer rcvtok;
  wxString tok;
  long int longvalue;
  struct TEDChatRoom *room;

  // VERIFICAMOS QUE NUESTRA VERSION DEL CLIENTE ES VALIDA
  sndmsg=_T("CE ")+wxString::Format("%d",roomindex)+_T("\n");
  TCPConn->SendMessage(sndmsg);
  rcvmsg=TCPConn->WaitMessage();
  ::wxSafeShowMessage(_("Titanes"),rcvmsg);
  rcvtok=wxStringTokenizer(rcvmsg);
  if (rcvtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
    return FALSE;
  }
  tok=rcvtok.GetNextToken();
  if (tok==_T("OK"))
  {
  }
  else if (tok==_T("NO"))
  {
  }
  return FALSE;
}

