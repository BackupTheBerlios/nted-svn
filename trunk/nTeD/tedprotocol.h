#ifndef _TEDPROTOCOL_H_
#define _TEDPROTOCOL_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "tedprotocol.cpp"
#endif

/*!
 * Includes
 */

#include <wx/tokenzr.h>
#include <wx/hashmap.h>
//#include <wx/dynarray.h>
#include "tcpconnection.h"

/*!
 * Forward declarations
 */

struct TEDChatter
{
  wxString Name;
  wxInt32 Id;
  wxInt32 DeckValue;
  wxInt32 Rank;
};

WX_DECLARE_HASH_MAP(wxInt32,struct TEDChatter *,wxIntegerHash,wxIntegerEqual,TEDChatterHash);

struct TEDChatRoom
{
  wxInt32 RoomId;
  wxString RoomName;
};

WX_DEFINE_ARRAY(struct TEDChatRoom *,TEDChatRoomArray);

struct TEDMovingCard
{
  wxInt32 srcdeckid;
  wxInt32 dstdeckid;
  wxInt32 cardid;
  wxInt32 carduid;
};

WX_DEFINE_ARRAY(struct TEDMovingCard *,TEDMovingCardArray);

WX_DEFINE_ARRAY(wxInt32,TEDCardIdArray);

struct TEDCard
{
  wxInt32 Id;
  wxInt32 Type;
  wxInt32 Attack;
  wxInt32 Defense;
  wxInt32 Gold;
  wxInt32 Max;
  wxString Cost;
  wxString Freq;
  wxString Name;
  wxString Text;
  TEDCardIdArray UId;
};

WX_DECLARE_HASH_MAP(wxInt32,struct TEDCard *,wxIntegerHash,wxIntegerEqual,TEDCardHash);

struct TEDDeck
{
  wxInt32 DeckId;
  wxString DeckName;
  TEDCardHash Cards;
};

WX_DECLARE_HASH_MAP(wxInt32,struct TEDDeck *,wxIntegerHash,wxIntegerEqual,TEDDeckHash);

struct TEDUser
{
  wxString Name;
  wxInt32 Wins;
  wxInt32 Looses;
  wxInt32 Retired;
  wxInt32 Gold;
  wxInt32 DeckValue;
  wxInt32 Rank;
  TEDChatRoomArray Rooms;
  TEDChatterHash Chatters;
  wxInt32 Room;
  TEDDeckHash Decks;
};

/*!
 * TEDProtocol class declaration
 */
class TEDProtocol
{
	public:
	  TEDProtocol();
    void Connect();
    void Login(wxString UserName,wxString UserPass);
	  wxString GetMessage();
	  wxString WaitMessage();
	  void SendMessage(wxString msg);
	  void Disconnect();
	  bool IsConnected();
	  bool IsLogged();
	  bool IsChatting();
	  void SetChatting(bool chatting);
	  wxInt32 GetNumChatRooms();
	  struct TEDChatRoom *GetChatRoom(wxInt32 roomindex);
	  wxString GetChatRoomName(wxInt32 roomindex);
	  bool ChatEnter(wxInt32 roomindex);
	  bool ChatExit();
	  wxInt32 GetUserChatRoomID();
	  wxInt32 GetTryRoomID();
	  wxInt32 GetRecoverRoomID();
	  void SetUserChatRoomID(wxInt32 roomid);
	  void SetTryRoomID(wxInt32 roomid);
	  void SetRecoverRoomID(wxInt32 roomid);
	  void AddUser(struct TEDChatter *chatter);
	  void RemoveUser(wxInt32 userid);
	  struct TEDChatter *GetUser(wxInt32 userid);
	  void DeckEdit();
	  void DeckExit();
	  bool IsEditing();
	  void SetEditing(bool editing);
	  wxInt32 GetActiveDeckID();
	  void SetActiveDeckID(wxInt32 deckid);
    void DeckList();
    bool IsGettingDeckList();
    void SetGettingDeckList(bool gettingdecklist);
    void AddDeck(wxInt32 deckid,wxString deckname);
    void ClearDeck(wxInt32 deckid);
    void DeckDescribe(wxInt32 deckid);
    bool IsGettingCardList();
    void SetGettingCardList(bool gettingcardlist);
    bool AlreadyHaveCardType(wxInt32 deckid,wxInt32 cardid);
    void AddCard(wxInt32 deckid,wxInt32 cardid,struct TEDCard *card);
    void AddCardUID(wxInt32 deckid,wxInt32 cardid,wxInt32 carduid);
    void RemoveCardUID(wxInt32 deckid,wxInt32 cardid,wxInt32 carduid);
    struct TEDCard *GetCard(wxInt32 deckid,wxInt32 cardid);
    void SetCurrentDeckId(wxInt32 deckid);
    wxInt32 GetCurrentDeckId();
    void DeckMove(wxInt32 srcdeckid,wxInt32 dstdeckid,wxInt32 cardid,wxInt32 carduid);
    struct TEDMovingCard *GetMovingCard();
    struct TEDDeck *GetDeck(wxInt32 deckid);
    void DeckNew(wxString deckname);
    wxString GetNewDeck();
    void DeckClear(wxint32 deckid);
	private:
	  TCPConnection *TCPConn;
	  struct TEDUser User;
	  bool m_logged;
	  bool m_chatting;
    wxInt32 m_tryroom;
    wxInt32 m_recoverroom;
    wxInt32 m_actdeck;
    bool m_editing;
    bool m_gettingdecklist;
    bool m_gettingcardlist;
    wxInt32 m_currentdeck;
    TEDMovingCardArray m_cardsmoving;
    wxArrayString m_newdecks;
/*
	  wxSocketClient *Conn;
	  wxTextInputStream *Input;
    wxTextOutputStream *Output;
    wxArrayString *MsgList;
    TCPThread ListenThread;
    void Connect();
    void StartListening();
	  void Listener();
	  void SendMessage(wxString Msg);
*/
};


#endif // _TEDPROTOCOL_H_

