/////////////////////////////////////////////////////////////////////////////
// Name:        chatdialog.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/14/04 19:05:22
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _CHATDIALOG_H_
#define _CHATDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "chatdialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
//#include "chatdialog_symbols.h"
#include "wx/listctrl.h"
////@end includes

#include "tedprotocol.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ChatDialog 10000
#define SYMBOL_WXCHATDIALOG_STYLE 0
#define SYMBOL_WXCHATDIALOG_TITLE _("Chat")
#define SYMBOL_WXCHATDIALOG_IDNAME ChatDialog
#define SYMBOL_WXCHATDIALOG_SIZE wxSize(566, 348)
#define SYMBOL_WXCHATDIALOG_POSITION wxDefaultPosition
#define MensajesTextCtrlID 10001
#define MensajeTextCtrlID 10002
#define EnviarButtonID 10003
#define UsuariosListCtrlID 10004
#define CanalesListCtrlID 10005
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxChatDialog class declaration
 */

int wxCALLBACK wxListCompareFunction(long item1, long item2, long sortData);

class wxChatDialog: public wxPanel
{    
    DECLARE_CLASS( wxChatDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxChatDialog( );
    wxChatDialog( wxWindow* parent, wxWindowID id = SYMBOL_WXCHATDIALOG_IDNAME, const wxPoint& pos = SYMBOL_WXCHATDIALOG_POSITION, const wxSize& size = SYMBOL_WXCHATDIALOG_SIZE, long style = SYMBOL_WXCHATDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXCHATDIALOG_IDNAME, const wxPoint& pos = SYMBOL_WXCHATDIALOG_POSITION, const wxSize& size = SYMBOL_WXCHATDIALOG_SIZE, long style = SYMBOL_WXCHATDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxChatDialog event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for EnviarButtonID
    void OnEnviarbuttonClick( wxCommandEvent& event );

////@end wxChatDialog event handler declarations
    void OnChatRoomSelected( wxListEvent& event );

////@begin wxChatDialog member function declarations

////@end wxChatDialog member function declarations
    void SetChannelNames();
    void AddUser(struct TEDChatter *chatter);
	  void RemoveUser(wxInt32 userid);

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxChatDialog member variables
    wxTextCtrl* MensajesTextCtrl;
    wxTextCtrl* MensajeTextCtrl;
    wxButton* EnviarButton;
    wxListCtrl* UsuariosListCtrl;
    wxListCtrl* CanalesListCtrl;
    TEDProtocol *m_TEDProtocol;
////@end wxChatDialog member variables
};

#endif
    // _CHATDIALOG_H_
