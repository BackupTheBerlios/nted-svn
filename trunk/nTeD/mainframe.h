/////////////////////////////////////////////////////////////////////////////
// Name:        mainframe.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     02/23/04 15:40:11
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

#ifdef __GNUG__
#pragma interface "mainframe.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "mainframe_symbols.h"
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
#define MainFrame 10000
#define MainToolBar 10001
#define ConectarTool 10002
#define ChatTool 10003
#define BarajasTool 10004
#define InfoTool 10005
#define PrefTool 10006
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * MainFrame class declaration
 */

class MainFrame: public wxFrame
{    
    DECLARE_CLASS( MainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    MainFrame( );
    MainFrame( wxWindow* parent, wxWindowID id = -1, const wxString& caption = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    bool Create( wxWindow* parent, wxWindowID id = -1, const wxString& caption = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creates the controls and sizers
    void CreateControls();

////@begin MainFrame event handler declarations

////@end MainFrame event handler declarations

////@begin MainFrame member function declarations

////@end MainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin MainFrame member variables
////@end MainFrame member variables
};

#endif
    // _MAINFRAME_H_
