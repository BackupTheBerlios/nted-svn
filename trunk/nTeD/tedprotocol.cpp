
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
  m_actdeck=-1;
  m_editing=FALSE;
  m_gettingdecklist=FALSE;
  m_gettingcardlist=FALSE;
  m_currentdeck=-1;
  m_cardsmoving.Clear();
  m_newdecks.Clear();
  m_decksrenaming.Clear();
  m_decksactivating.Clear();
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
#if 0
  long int longvalue;
  struct TEDChatRoom *room;
#endif

  m_tryroom=roomindex;
  sndmsg=_T("CE ")+wxString::Format("%d",roomindex)+_T("\n");
  TCPConn->SendMessage(sndmsg);
#if 0
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
#endif
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

void TEDProtocol::ClearDeck(wxInt32 deckid)
{
  User.Decks[deckid]->Cards.clear();
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

bool TEDProtocol::AlreadyHaveCardType(wxInt32 deckid,wxInt32 cardid)
{
  TEDDeckHash::iterator itdeck;
  TEDCardHash::iterator itcard;

  // I'M NOT SURE ON THIS MOMENT BUT I THINK THIS WILL ALWAYS RETURN
  // A CORRECT DECK VALUE SO WE CAN REMOVE THIS CHECK
  itdeck=User.Decks.find(deckid);
  if (itdeck==User.Decks.end())
  {
    return FALSE;
  }
  itcard=itdeck->second->Cards.find(cardid);
  if (itcard==itdeck->second->Cards.end())
  {
    return FALSE;
  }
  return TRUE;
}

void TEDProtocol::AddCard(wxInt32 deckid,wxInt32 cardid,struct TEDCard *card)
{
  User.Decks[deckid]->Cards[cardid]=card;
}

void TEDProtocol::AddCardUID(wxInt32 deckid,wxInt32 cardid,wxInt32 carduid)
{
  wxInt32 *uid;

  uid=new wxInt32;
  *uid=carduid;
  User.Decks[deckid]->Cards[cardid]->UId.Add(uid);
}

void TEDProtocol::RemoveCardUID(wxInt32 deckid,wxInt32 cardid,wxInt32 carduid)
{
  wxInt32 index;

  wxInt32 *uid;

  uid=new wxInt32;
  *uid=carduid;
  index=User.Decks[deckid]->Cards[cardid]->UId.Index(uid);
  if (index==wxNOT_FOUND)
  {
    return;
  }
  User.Decks[deckid]->Cards[cardid]->UId.Remove(uid);
  if (User.Decks[deckid]->Cards[cardid]->UId.IsEmpty()==TRUE)
  {
    User.Decks[deckid]->Cards.erase(cardid);
  }
}

struct TEDCard *TEDProtocol::GetCard(wxInt32 deckid,wxInt32 cardid)
{
  return User.Decks[deckid]->Cards[cardid];
}

void TEDProtocol::SetCurrentDeckId(wxInt32 deckid)
{
  m_currentdeck=deckid;
}

wxInt32 TEDProtocol::GetCurrentDeckId()
{
  return m_currentdeck;
}

void TEDProtocol::DeckMove(wxInt32 srcdeckid,wxInt32 dstdeckid,wxInt32 cardid,wxInt32 carduid)
{
  wxString sndmsg;
  struct TEDMovingCard *movingcard;

  movingcard=new struct TEDMovingCard;
  movingcard->srcdeckid=srcdeckid;
  movingcard->dstdeckid=dstdeckid;
  movingcard->cardid=cardid;
  movingcard->carduid=carduid;
  m_cardsmoving.Add(movingcard);
  sndmsg=_T("EM ")+wxString::Format("%d %d",dstdeckid,carduid)+_T("\n");
  TCPConn->SendMessage(sndmsg);
}

struct TEDMovingCard *TEDProtocol::GetMovingCard()
{
  struct TEDMovingCard *movingcard;
  
  if (m_cardsmoving.IsEmpty()==TRUE)
  {
    return NULL;
  }
  movingcard=m_cardsmoving[0];
  m_cardsmoving.RemoveAt(0);
  return movingcard;
}

struct TEDDeck *TEDProtocol::GetDeck(wxInt32 deckid)
{
  TEDDeckHash::iterator itdeck;

  itdeck=User.Decks.find(deckid);
  if (itdeck==User.Decks.end())
  {
    return NULL;
  }
  return itdeck->second;
}

void TEDProtocol::DeckNew(wxString deckname)
{
  wxString sndmsg;

  m_newdecks.Add(deckname);
  sndmsg=_T("EN ")+deckname+_T("\n");
  TCPConn->SendMessage(sndmsg);
}

wxString TEDProtocol::GetNewDeck()
{
  wxString deckname;

  if (m_newdecks.IsEmpty()==TRUE)
  {
    return wxEmptyString;
  }
  deckname=m_newdecks[0];
  m_newdecks.RemoveAt(0);
  return deckname;
}

void TEDProtocol::DeckClear(wxInt32 deckid)
{
  wxString sndmsg;

  sndmsg=_T("EK ")+wxString::Format("%d",deckid)+_T("\n");
  TCPConn->SendMessage(sndmsg);
}

void TEDProtocol::DeckRename(wxInt32 deckid,wxString deckname)
{
  wxString sndmsg;
  struct TEDRenamingDeck *renamingdeck;

  renamingdeck=new struct TEDRenamingDeck;
  renamingdeck->deckid=deckid;
  renamingdeck->deckname=deckname;
  m_decksrenaming.Add(renamingdeck);
  sndmsg=_T("ER ")+wxString::Format("%d ",deckid)+deckname+_T("\n");
  TCPConn->SendMessage(sndmsg);
}

struct TEDRenamingDeck *TEDProtocol::GetRenamingDeck()
{
  struct TEDRenamingDeck *renamingdeck;
  
  if (m_decksrenaming.IsEmpty()==TRUE)
  {
    return NULL;
  }
  renamingdeck=m_decksrenaming[0];
  m_decksrenaming.RemoveAt(0);
  return renamingdeck;
}

void TEDProtocol::DeckActive(wxInt32 deckid)
{
  wxString sndmsg;
  wxInt32 *did;

  did=new wxInt32;
  *did=deckid;
  m_decksactivating.Add(did);
  sndmsg=_T("EA ")+wxString::Format("%d",deckid)+_T("\n");
  TCPConn->SendMessage(sndmsg);
}

wxInt32 TEDProtocol::GetActivatingDeck()
{
  wxInt32 deckid;
  wxInt32 *did;

  if (m_decksactivating.IsEmpty()==TRUE)
  {
    return -1;
  }
  did=m_decksactivating[0];
  m_decksactivating.RemoveAt(0);
  deckid=*did;
  delete did;
  return deckid;
}

void TEDProtocol::DeckGet()
{
  wxString sndmsg;

  sndmsg=_T("EG 1\n");
  TCPConn->SendMessage(sndmsg);
}

wxInt32 TEDProtocol::GetUserGold()
{
  return User.Gold;
}

void TEDProtocol::SetUserGold(wxInt32 gold)
{
  User.Gold=gold;
}

wxInt32 TEDProtocol::GetDeckNumCards(wxInt32 deckid)
{
  struct TEDDeck *deck;
  TEDCardHash::iterator it;
  wxInt32 numcards;

  deck=GetDeck(deckid);
  if (deck==NULL)
  {
    return -1;
  }
  numcards=0;
  for (it=deck->Cards.begin();it!=deck->Cards.end();it++)
  {
    numcards=numcards+it->second->UId.Count();
  }
  return numcards;
}

void TEDProtocol::SetOpponent(wxString name,wxInt32 deckvalue,wxInt32 rank)
{
  Duel.Local.Name=User.Name;
  Duel.Local.DeckValue=User.DeckValue;
  Duel.Local.Rank=User.Rank;
  Duel.Local.Hand.Clear();
  Duel.Local.Table.Clear();
  Duel.Local.Combat.Clear();
  Duel.Local.Graveyard.Clear();
  Duel.Remote.Name=name;
  Duel.Remote.DeckValue=deckvalue;
  Duel.Remote.Rank=rank;
  Duel.Remote.Hand.Clear();
  Duel.Remote.Table.Clear();
  Duel.Remote.Combat.Clear();
  Duel.Remote.Graveyard.Clear();
}

void TEDProtocol:: GameStart()
{
  wxString sndmsg;

  sndmsg=_T("GS OK\n");
  TCPConn->SendMessage(sndmsg);
}

