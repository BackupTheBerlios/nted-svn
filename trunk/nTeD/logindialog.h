/////////////////////////////////////////////////////////////////////////////
// Name:        logindialog.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     02/24/04 15:29:08
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _LOGINDIALOG_H_
#define _LOGINDIALOG_H_

#ifdef __GNUG__
#pragma interface "logindialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "logindialog_symbols.h"
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
#define LoginDialog 10000
#define UsuarioStatic 10004
#define UsuarioTextCtrl 10001
#define ContrasenaStatic 10005
#define ContrasenaTextCtrl 10002
#define ConectarButton 10003
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * LoginDialog class declaration
 */

class LoginDialog: public wxDialog
{    
    DECLARE_CLASS( LoginDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    LoginDialog( );
    LoginDialog( wxWindow* parent, wxWindowID id = -1, const wxString& caption = _("Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = -1, const wxString& caption = _("Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creates the controls and sizers
    void CreateControls();

////@begin LoginDialog event handler declarations

////@end LoginDialog event handler declarations

////@begin LoginDialog member function declarations

////@end LoginDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin LoginDialog member variables
////@end LoginDialog member variables
};

#endif
    // _LOGINDIALOG_H_
