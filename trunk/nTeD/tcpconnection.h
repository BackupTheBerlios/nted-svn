#ifndef _TCPCONNECTION_H_
#define _TCPCONNECTION_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "tcpconnection.cpp"
#endif

/*!
 * Includes
 */
//#include <wx/thread.h>
#include <wx/socket.h>
#include <wx/sckstrm.h>
#include <wx/txtstrm.h>
//#include <wx/string.h>
//#include <wx/arrstr.h>
//#inlcude <wx/utils.h>

/*!
 * Forward declarations
 */


#define CONNECTTIMEOUT 10
#define TEDHOST "192.168.0.1"
#define TEDPORT 3771

/*!
 * TCPThread class declaration
 */

class TCPThread:public wxThread
{
	public:
    TCPThread(wxTextInputStream *Input,wxArrayString *MsgList);
    // thread execution starts here
    virtual void *Entry();
  private:
    wxTextInputStream *m_input;
    wxArrayString *m_msglist;
};

/*!
 * TCPConnection class declaration
 */

class TCPConnection
{
	public:
    TCPConnection();
    void Connect();
	  void SendMessage(wxString Msg);
	  wxString GetMessage();
	  wxString WaitMessage();
	  void Disconnect();
	  bool IsConnected();
  private:
    wxIPV4address *address;
	  wxSocketClient *Conn;
    wxSocketInputStream *sockinstrm;
    wxSocketOutputStream *sockoutstrm;
	  wxTextInputStream *Input;
    wxTextOutputStream *Output;
    wxArrayString *MsgList;
    TCPThread *ListenThread;
};

#endif // _TCPCONNECTION_H_
