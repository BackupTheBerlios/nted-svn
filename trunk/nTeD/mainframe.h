/////////////////////////////////////////////////////////////////////////////
// Name:        mainframe.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/14/04 16:36:40
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "mainframe.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
//#include "mainframe_symbols.h"
#include "wx/frame.h"
#include "wx/toolbar.h"
////@end includes

#include "logindialog.h"
#include "chatdialog.h"
#include "deckdialog.h"
#include "infodialog.h"
#include "tedprotocol.h"
#include "tcpconnection.h"


/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations
class wxLoginDialog;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define MainFrame 10000
#define SYMBOL_WXMAINFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX
#define SYMBOL_WXMAINFRAME_TITLE _("Titanes: el Destierro")
#define SYMBOL_WXMAINFRAME_IDNAME MainFrame
#define SYMBOL_WXMAINFRAME_SIZE wxSize(600, 300)
#define SYMBOL_WXMAINFRAME_POSITION wxDefaultPosition
#define MainToolBarID 10001
#define ConectarTool 10002
#define ChatTool 10003
#define BarajasTool 10004
#define InfoTool 10005
#define PrefTool 10006
#define SalirTool 10007
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxMainFrame class declaration
 */

class wxMainFrame: public wxFrame
{    
    DECLARE_CLASS( wxMainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxMainFrame( );
    wxMainFrame( wxWindow* parent, wxWindowID id = SYMBOL_WXMAINFRAME_IDNAME, const wxString& caption = SYMBOL_WXMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_WXMAINFRAME_POSITION, const wxSize& size = SYMBOL_WXMAINFRAME_SIZE, long style = SYMBOL_WXMAINFRAME_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXMAINFRAME_IDNAME, const wxString& caption = SYMBOL_WXMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_WXMAINFRAME_POSITION, const wxSize& size = SYMBOL_WXMAINFRAME_SIZE, long style = SYMBOL_WXMAINFRAME_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxMainFrame event handler declarations

    /// wxEVT_CLOSE_WINDOW event handler for MainFrame
    void OnCloseWindow( wxCloseEvent& event );

    /// wxEVT_SIZE event handler for MainFrame
    void OnSize( wxSizeEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ConectarTool
    void OnConectartoolClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ChatTool
    void OnChattoolClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for BarajasTool
    void OnBarajastoolClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for InfoTool
    void OnInfotoolClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for PrefTool
    void OnPreftoolClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for SalirTool
    void OnSalirtoolClick( wxCommandEvent& event );

////@end wxMainFrame event handler declarations

    void OnIdle(wxIdleEvent &event);
    void ProcessMessage(wxString msg);
    void ProcessChatEnter(wxString msg);
    void ProcessDeckEdit(wxString msg);
    void ProcessGameStart(wxString msg);
    void ProcessChatExit(wxString msg);
    void ProcessChatMessage(wxString msg);
    void ProcessDuelChallenged(wxString msg);
    void ProcessDuelCancelled(wxString msg);
    void ProcessChatUser(wxString msg);
    void ProcessDeckList(wxString msg);
    void ProcessDeckDescribe(wxString msg);
    void ProcessDeckNew(wxString msg);
    void ProcessDeckMove(wxString msg);
    void ProcessDeckClear(wxString msg);
    void ProcessDeckRename(wxString msg);
    void ProcessDeckActive(wxString msg);
    void ProcessDeckGet(wxString msg);
    void ProcessDeckExit(wxString msg);
    void ProcessGameFinish(wxString msg);
    void ProcessGameExit(wxString msg);
    void ProcessGameInfo(wxString msg);
    void ProcessGamePhase(wxString msg);
    void ProcessGameCard(wxString msg);
    void ProcessGameText(wxString msg);
    void ProcessGameSelect(wxString msg);
    void ProcessGameUse(wxString msg);
    void ProcessUnknownMessage(wxString msg);

////@begin wxMainFrame member function declarations

////@end wxMainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();
    void UpdateToolbar(int id);

////@begin wxMainFrame member variables
    wxToolBar* MainToolBar;
    wxPanel *m_ActiveWnd;
    wxLoginDialog *m_LoginWnd;
    wxChatDialog *m_ChatWnd;
    wxDeckDialog *m_DeckWnd;
    wxFlexGridSizer *m_mainsizer;
    TEDProtocol *m_TEDProtocol;
    wxInfoDialog *m_InfoWnd;
////@end wxMainFrame member variables
};

#endif // _MAINFRAME_H_
