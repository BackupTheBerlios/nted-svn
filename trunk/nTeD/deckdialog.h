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

#include <wx/wfstream.h>
#include <wx/image.h>
#include "tedprotocol.h"

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
#define ReserveNumCardsStaticTextID 10010
#define CardStaticBitmapID 10008
#define GoldStaticTextID 10012
#define ComprarSobreButtonID 10002
#define CrearBarajaButtonID 10003
#define RenombrarBarajaButtonID 10004
#define BorrarBarajaButtonID 10005
#define ActivarBarajaButtonID 10006
#define DecksComboBoxID 10009
#define CurrentDeckListCtrlID 10007
#define CurrentNumCardsStaticTextID 10011
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

int wxCALLBACK wxListCompareFunction2(long item1, long item2, long sortData);

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

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ReserveListCtrlID
    void OnReservelistctrlidSelected( wxListEvent& event );

    /// wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for ReserveListCtrlID
    void OnReservelistctrlidItemActivated( wxListEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ComprarSobreButtonID
    void OnComprarsobrebuttonidClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for CrearBarajaButtonID
    void OnCrearbarajabuttonidClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for RenombrarBarajaButtonID
    void OnRenombrarbarajabuttonidClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for BorrarBarajaButtonID
    void OnBorrarbarajabuttonidClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ActivarBarajaButtonID
    void OnActivarbarajabuttonidClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_COMBOBOX_SELECTED event handler for DecksComboBoxID
    void OnDeckscomboboxidSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for CurrentDeckListCtrlID
    void OnCurrentdecklistctrlidSelected( wxListEvent& event );

    /// wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for CurrentDeckListCtrlID
    void OnCurrentdecklistctrlidItemActivated( wxListEvent& event );

////@end wxDeckDialog event handler declarations

    void ClearDecks();
    void ProcessDeckList(wxInt32 deckid,wxString deckname);
    void LoadReserveDeck();
    void ProcessDeckDescribe(wxInt32 deckid,wxInt32 carduid,wxInt32 cardid);
    void ProcessDeckMove(struct TEDMovingCard *movingcard);
    void ProcessDeckNew(wxString deckname,wxInt32 deckid);
    void ProcessDeckClear();
    void ProcessDeckRename();
    void ProcessDeckActive();
    void ProcessDeckGet(wxInt32 gold);
    void OnLeftDown(wxMouseEvent& event);
    void LoadSmallCardBitmap(struct TEDCard *card,wxBitmap *cardbitmap,bool frombig=FALSE);
    void LoadBigCardBitmap(struct TEDCard *card,wxBitmap *cardbitmap);
////@begin wxDeckDialog member function declarations


    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxDeckDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxDeckDialog member variables
    wxFlexGridSizer* fgsmain;
    wxFlexGridSizer* fgschild;
    wxFlexGridSizer* fgsleft;
    wxListCtrl* ReserveListCtrl;
    wxStaticText* ReserveNumCardsStaticText;
    wxFlexGridSizer* fgscenter;
    wxFlexGridSizer* fgscenterchild;
    wxStaticBitmap* CardStaticBitmap;
    wxStaticText* GoldStaticText;
    wxFlexGridSizer* fgsbuttons;
    wxButton* ComprarSobreButton;
    wxButton* CrearBarajaButton;
    wxButton* RenombrarBarajaButton;
    wxButton* BorrarBarajaButton;
    wxButton* ActivarBarajaButton;
    wxFlexGridSizer* fgsright;
    wxComboBox* DecksComboBox;
    wxListCtrl* CurrentDeckListCtrl;
    wxStaticText* CurrentNumCardsStaticText;
    TEDProtocol* m_TEDProtocol;
////@end wxDeckDialog member variables
};

#endif
    // _DECKDIALOG_H_
