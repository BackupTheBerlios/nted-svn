/////////////////////////////////////////////////////////////////////////////
// Name:        chatdialog.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     02/27/04 09:53:08
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _CHATDIALOG_H_
#define _CHATDIALOG_H_

#ifdef __GNUG__
#pragma interface "chatdialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "chatdialog_symbols.h"
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
 * ChatDialog class declaration
 */

class ChatDialog: public wxDialog
{    
    DECLARE_CLASS( ChatDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    ChatDialog( );
    ChatDialog( wxWindow* parent, wxWindowID id = -1, const wxString& caption = _("Chat"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = -1, const wxString& caption = _("Chat"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creates the controls and sizers
    void CreateControls();

////@begin ChatDialog event handler declarations

////@end ChatDialog event handler declarations

////@begin ChatDialog member function declarations

////@end ChatDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ChatDialog member variables
////@end ChatDialog member variables
};

#endif
    // _CHATDIALOG_H_
