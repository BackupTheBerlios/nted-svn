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
#include "chatdialog_symbols.h"
#include "wx/listctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ChatDialog 10000
#define SYMBOL_WXCHATDIALOG_STYLE wxCLOSE_BOX
#define SYMBOL_WXCHATDIALOG_TITLE _("Chat")
#define SYMBOL_WXCHATDIALOG_IDNAME ChatDialog
#define SYMBOL_WXCHATDIALOG_SIZE wxSize(580, 350)
#define SYMBOL_WXCHATDIALOG_POSITION wxDefaultPosition
#define ID_TEXTCTRL 10001
#define ID_TEXTCTRL1 10002
#define EnviarButton 10003
#define ID_LISTCTRL 10004
#define ID_LISTCTRL1 10005
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

////@end wxChatDialog event handler declarations

////@begin wxChatDialog member function declarations

////@end wxChatDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxChatDialog member variables
////@end wxChatDialog member variables
};

#endif
    // _CHATDIALOG_H_
