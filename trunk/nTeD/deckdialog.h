/////////////////////////////////////////////////////////////////////////////
// Name:        deckdialog.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     05/03/04 19:45:26
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DECKDIALOG_H_
#define _DECKDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "deckdialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/listctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxFlexGridSizer;
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define SYMBOL_WXDECKDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXDECKDIALOG_TITLE _("Baraja")
#define SYMBOL_WXDECKDIALOG_IDNAME ID_DIALOG
#define SYMBOL_WXDECKDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_WXDECKDIALOG_POSITION wxDefaultPosition
#define ReserveListCtrlID 10001
#define CardStaticBitmapID 10008
#define ID_BUTTON 10002
#define ID_BUTTON1 10003
#define ID_BUTTON2 10004
#define ID_BUTTON3 10005
#define ID_BUTTON4 10006
#define ID_LISTCTRL1 10007
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxDeckDialog class declaration
 */

class wxDeckDialog: public wxPanel
{    
    DECLARE_CLASS( wxDeckDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxDeckDialog( );
    wxDeckDialog( wxWindow* parent, wxWindowID id = SYMBOL_WXDECKDIALOG_IDNAME, const wxString& caption = SYMBOL_WXDECKDIALOG_TITLE, const wxPoint& pos = SYMBOL_WXDECKDIALOG_POSITION, const wxSize& size = SYMBOL_WXDECKDIALOG_SIZE, long style = SYMBOL_WXDECKDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXDECKDIALOG_IDNAME, const wxString& caption = SYMBOL_WXDECKDIALOG_TITLE, const wxPoint& pos = SYMBOL_WXDECKDIALOG_POSITION, const wxSize& size = SYMBOL_WXDECKDIALOG_SIZE, long style = SYMBOL_WXDECKDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxDeckDialog event handler declarations

////@end wxDeckDialog event handler declarations

////@begin wxDeckDialog member function declarations

////@end wxDeckDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxDeckDialog member variables
    wxFlexGridSizer* fgsmain;
    wxFlexGridSizer* fgschild;
    wxFlexGridSizer* fgsleft;
    wxListCtrl* ReserveListCtrl;
    wxFlexGridSizer* fgscenter;
    wxFlexGridSizer* fgscenterchild;
    wxStaticBitmap* CardStaticBitmap;
    wxFlexGridSizer* fgsbuttons;
    wxFlexGridSizer* fgsright;
////@end wxDeckDialog member variables
};

#endif
    // _DECKDIALOG_H_
