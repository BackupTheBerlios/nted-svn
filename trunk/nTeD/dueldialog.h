/////////////////////////////////////////////////////////////////////////////
// Name:        dueldialog.h
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     05/19/04 12:53:41
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DUELDIALOG_H_
#define _DUELDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "dueldialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxFlexGridSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG1 10013
#define SYMBOL_WXDUELDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WXDUELDIALOG_TITLE _("Duelo")
#define SYMBOL_WXDUELDIALOG_IDNAME ID_DIALOG1
#define SYMBOL_WXDUELDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_WXDUELDIALOG_POSITION wxDefaultPosition
#define OpponentStaticTextID 10015
#define OpponentLFStaticTextID 10016
#define CardStaticBitmapID 10014
#define MensajesTextCtrlID 10017
#define MensajeTextCtrlID 10018
#define PlayerStaticTextID 10019
#define PlayerLFStaticTextID 10020
#define PasarButtonID 10021
#define OppDeckCardStaticBitmapID 10022
#define OppGraveCardStaticBitmapID 10023
#define OppDeckCard2StaticBitmapID 10024
#define OppGraveCard2StaticBitmapID 10025
#define PlayerDeckCard2StaticBitmapID 10026
#define PlayerGraveCard2StaticBitmapID 10027
#define PlayerDeckCardStaticBitmapID 10028
#define PlayerGraveCardStaticBitmapID 10029
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * wxDuelDialog class declaration
 */

class wxDuelDialog: public wxPanel
{    
    DECLARE_CLASS( wxDuelDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxDuelDialog( );
    wxDuelDialog( wxWindow* parent, wxWindowID id = SYMBOL_WXDUELDIALOG_IDNAME, const wxString& caption = SYMBOL_WXDUELDIALOG_TITLE, const wxPoint& pos = SYMBOL_WXDUELDIALOG_POSITION, const wxSize& size = SYMBOL_WXDUELDIALOG_SIZE, long style = SYMBOL_WXDUELDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WXDUELDIALOG_IDNAME, const wxString& caption = SYMBOL_WXDUELDIALOG_TITLE, const wxPoint& pos = SYMBOL_WXDUELDIALOG_POSITION, const wxSize& size = SYMBOL_WXDUELDIALOG_SIZE, long style = SYMBOL_WXDUELDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxDuelDialog event handler declarations

    /// wxEVT_COMMAND_TEXT_ENTER event handler for MensajeTextCtrlID
    void OnMensajetextctrlidEnter( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for PasarButtonID
    void OnPasarbuttonidClick( wxCommandEvent& event );

////@end wxDuelDialog event handler declarations

////@begin wxDuelDialog member function declarations


    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxDuelDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxDuelDialog member variables
    wxFlexGridSizer* fgsmain;
    wxFlexGridSizer* fgschild;
    wxFlexGridSizer* fgsleft;
    wxStaticText* OpponentStaticText;
    wxStaticText* OpponentLFStaticText;
    wxStaticBitmap* CardStaticBitmap;
    wxTextCtrl* MensajesTextCtrl;
    wxTextCtrl* MensajeTextCtrl;
    wxStaticText* PlayerStaticText;
    wxStaticText* PlayerLFStaticText;
    wxButton* PasarButton;
    wxFlexGridSizer* fgscenter;
    wxFlexGridSizer* fgsright;
    wxFlexGridSizer* fgsopptbl;
    wxStaticBitmap* OppDeckCardStaticBitmap;
    wxStaticBitmap* OppGraveCardStaticBitmap;
    wxStaticBitmap* OppDeckCard2StaticBitmap;
    wxStaticBitmap* OppGraveCard2StaticBitmap;
    wxFlexGridSizer* fgsplayertbl;
    wxStaticBitmap* PlayerDeckCard2StaticBitmap;
    wxStaticBitmap* PlayerGraveCard2StaticBitmap;
    wxStaticBitmap* PlayerDeckCardStaticBitmap;
    wxStaticBitmap* PlayerGraveCardStaticBitmap;
////@end wxDuelDialog member variables
};

#endif
    // _DUELDIALOG_H_
