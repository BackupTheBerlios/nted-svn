/////////////////////////////////////////////////////////////////////////////
// Name:        infodialog.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/28/04 12:52:30
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _INFODIALOG_H_
#define _INFODIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "infodialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "infodialog_symbols.h"
#include "wx/html/htmlwin.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxHtmlWindow;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define InfoDialog 10000
#define SYMBOL_WXINFODIALOG_STYLE 0
#define SYMBOL_WXINFODIALOG_TITLE _("Información")
#define SYMBOL_WXINFODIALOG_IDNAME InfoDialog
#define SYMBOL_WXINFODIALOG_SIZE wxSize(400, 300)
#define SYMBOL_WXINFODIALOG_POSITION wxDefaultPosition
#define InfoHtmlWindowID 10003
#define LogTextCtrlID 10002
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxInfoDialog class declaration
 */

class wxInfoDialog: public wxPanel
{    
    DECLARE_CLASS( wxInfoDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxInfoDialog( );
    wxInfoDialog( wxWindow* parent, wxWindowID id = SYMBOL_WXINFODIALOG_IDNAME, const wxString& caption = SYMBOL_WXINFODIALOG_TITLE, const wxPoint& pos = SYMBOL_WXINFODIALOG_POSITION, const wxSize& size = SYMBOL_WXINFODIALOG_SIZE, long style = SYMBOL_WXINFODIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXINFODIALOG_IDNAME, const wxString& caption = SYMBOL_WXINFODIALOG_TITLE, const wxPoint& pos = SYMBOL_WXINFODIALOG_POSITION, const wxSize& size = SYMBOL_WXINFODIALOG_SIZE, long style = SYMBOL_WXINFODIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxInfoDialog event handler declarations

////@end wxInfoDialog event handler declarations

////@begin wxInfoDialog member function declarations

////@end wxInfoDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxInfoDialog member variables
    wxHtmlWindow* InfoHtmlWindow;
    wxTextCtrl* LogTextCtrl;
////@end wxInfoDialog member variables
};

#endif
    // _INFODIALOG_H_
