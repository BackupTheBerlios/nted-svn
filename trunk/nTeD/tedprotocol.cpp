
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
  m_chatting=FALSE;
  m_tryroom=0;
  m_recoverroom=0;
  m_gettingdecklist=FALSE;
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
  if (TCPConn->IsConnected()==FALSE)
  {
    m_chatting=FALSE;
    m_logged=FALSE;
    return FALSE;
  }
  return TRUE;
}

bool TEDProtocol::IsLogged()
{
  if (m_logged==FALSE)
  {
    m_chatting=FALSE;
    return FALSE;
  }
  IsConnected();
  return m_logged;
}

bool TEDProtocol::IsChatting()
{
  if (m_chatting==FALSE)
  {
    return FALSE;
  }
  IsLogged();
  return m_chatting;
}

void TEDProtocol::SetChatting(bool chatting)
{
  m_chatting=chatting;
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

  m_tryroom=roomindex;
  sndmsg=_T("CE ")+wxString::Format("%d",roomindex)+_T("\n");
  TCPConn->SendMessage(sndmsg);
/*
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
*/
  // ON THIS MOMENT WE RETURN FALSE BECAUSE WE NEED TO DECIDE
  // IF WE ARE GOING TO CHECK IF WE HAVE ENTERED THE CHANNEL HERE
  // OR IF WE ARE GOING TO CHECK IT WITH ALL OTHER MESSAGES
  // 10-05-2004
  // ON THIS MOMENT EVERYTHING IS GOING TO BE PROCCESSED AT THE PROCESSMESSAGE
  // FUNCTION. THE ONE AND ONLY EXCEPTION TO THIS RULE IS LOGIN.
  // WE SHOULD CHANGE THE RETURN TYPE TO VOID
  return FALSE;
}

bool TEDProtocol::ChatExit()
{
  wxString sndmsg;

  sndmsg=_T("CX\n");
  TCPConn->SendMessage(sndmsg);
  return FALSE;
}

wxInt32 TEDProtocol::GetUserChatRoomID()
{
  return User.Room;
}

wxInt32 TEDProtocol::GetTryRoomID()
{
  return m_tryroom;
}

wxInt32 TEDProtocol::GetRecoverRoomID()
{
  return m_recoverroom;
}

void TEDProtocol::SetUserChatRoomID(wxInt32 roomid)
{
  User.Room=roomid;
}

void TEDProtocol::SetTryRoomID(wxInt32 roomid)
{
  m_tryroom=roomid;
}

void TEDProtocol::SetRecoverRoomID(wxInt32 roomid)
{
  m_recoverroom=roomid;
}

void TEDProtocol::AddUser(struct TEDChatter *chatter)
{
  User.Chatters[chatter->Id]=chatter;
}

void TEDProtocol::RemoveUser(wxInt32 userid)
{
  User.Chatters.erase(userid);
}

struct TEDChatter *TEDProtocol::GetUser(wxInt32 userid)
{
  TEDChatterHash::iterator it;

  it=User.Chatters.find(userid);
  if (it==User.Chatters.end())
  {
    return NULL;
  }
  return it->second;
}

void TEDProtocol::DeckEdit()
{
  wxString sndmsg;

  sndmsg=_T("EE\n");
  TCPConn->SendMessage(sndmsg);
}

void TEDProtocol::DeckExit()
{
  wxString sndmsg;

  sndmsg=_T("EX\n");
  TCPConn->SendMessage(sndmsg);
}

bool TEDProtocol::IsEditing()
{
  return m_editing;
}

void TEDProtocol::SetEditing(bool editing)
{
  m_editing=editing;
}

wxInt32 TEDProtocol::GetActiveDeckID()
{
  return m_actdeck;
}

void TEDProtocol::SetActiveDeckID(wxInt32 deckid)
{
  m_actdeck=deckid;
}

void TEDProtocol::DeckList()
{
  wxString sndmsg;

  sndmsg=_T("EL\n");
  m_gettingdecklist=TRUE;
  User.Decks.clear();
  TCPConn->SendMessage(sndmsg);
}

bool TEDProtocol::IsGettingDeckList()
{
  return m_gettingdecklist;
}

void TEDProtocol::SetGettingDeckList(bool gettingdecklist)
{
  m_gettingdecklist=gettingdecklist;
}

void TEDProtocol::AddDeck(wxInt32 deckid,wxString deckname)
{
  struct TEDDeck *deck;

  deck=new struct TEDDeck;
  deck->DeckId=deckid;
  deck->DeckName=deckname;
  deck->Cards.clear();
  User.Decks[deckid]=deck;
}

void TEDProtocol::DeckDescribe(wxInt32 deckid)
{
  wxString sndmsg;

  sndmsg=_T("ED ")+wxString::Format("%d",deckid)+_T("\n");
  // WE WILL NOT NEED m_gettingcardlist BECAUSE WHEN WE BUY A NEW PACK OF CARDS
  // WE DON'T GET A LIST WITH ALL CARDS IN RESERVE DECK (WASTE OF TIME)
  // WE JUST GET A LIST OF THE NEW CARDS WE HAVE GOT
//  m_gettingcardlist=TRUE;
  TCPConn->SendMessage(sndmsg);
}

bool TEDProtocol::IsGettingCardList()
{
  return m_gettingcardlist;
}

void TEDProtocol::SetGettingCardList(bool gettingcardlist)
{
  m_gettingcardlist=gettingcardlist;
}


