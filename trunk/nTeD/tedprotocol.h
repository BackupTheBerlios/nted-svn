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

WX_DECLARE_HASH_MAP(wxString,struct TEDChatter *,wxStringHash,wxStringEqual,TEDChatterHash);

struct TEDChatRoom
{
  wxInt32 RoomId;
  wxString RoomName;
};

WX_DEFINE_ARRAY(struct TEDChatRoom *,TEDChatRoomArray);

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
	  void Disconnect();
	  bool IsConnected();
	private:
	  TCPConnection *TCPConn;
	  struct TEDUser User;
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

