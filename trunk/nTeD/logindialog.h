/////////////////////////////////////////////////////////////////////////////
// Name:        logindialog.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/07/04 14:06:17
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _LOGINDIALOG_H_
#define _LOGINDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "logindialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "logindialog_symbols.h"
////@end includes

#include <wx/msgdlg.h>
#include "tedprotocol.h"


/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define LoginDialogID 10000
#define SYMBOL_WXLOGINDIALOG_STYLE 0
#define SYMBOL_WXLOGINDIALOG_TITLE _("Login")
#define SYMBOL_WXLOGINDIALOG_IDNAME LoginDialogID
#define SYMBOL_WXLOGINDIALOG_SIZE wxSize(250, 180)
#define SYMBOL_WXLOGINDIALOG_POSITION wxDefaultPosition
#define UsuarioStaticID 10004
#define UsuarioTextCtrlID 10001
#define ContrasenaStaticID 10005
#define ContrasenaTextCtrlID 10002
#define ConectarButtonID 10003
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxLoginDialog class declaration
 */

class wxLoginDialog: public wxPanel
{    
    DECLARE_CLASS( wxLoginDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxLoginDialog( );
    wxLoginDialog( wxWindow* parent, wxWindowID id = SYMBOL_WXLOGINDIALOG_IDNAME, const wxPoint& pos = SYMBOL_WXLOGINDIALOG_POSITION, const wxSize& size = SYMBOL_WXLOGINDIALOG_SIZE, long style = SYMBOL_WXLOGINDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXLOGINDIALOG_IDNAME, const wxPoint& pos = SYMBOL_WXLOGINDIALOG_POSITION, const wxSize& size = SYMBOL_WXLOGINDIALOG_SIZE, long style = SYMBOL_WXLOGINDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxLoginDialog event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ConectarButtonID
    void OnConectarbuttonClick( wxCommandEvent& event );

////@end wxLoginDialog event handler declarations

////@begin wxLoginDialog member function declarations

////@end wxLoginDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxLoginDialog member variables
    wxStaticText* UsuarioStatic;
    wxTextCtrl* UsuarioTextCtrl;
    wxStaticText* ContrasenaStatic;
    wxTextCtrl* ContrasenaTextCtrl;
    wxButton* ConectarButton;
    TEDProtocol *m_TEDProtocol;
////@end wxLoginDialog member variables
};

#endif
    // _LOGINDIALOG_H_
