/////////////////////////////////////////////////////////////////////////////
// Name:        dueldialog.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     05/21/04 15:47:03
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "dueldialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "dueldialog.h"

////@begin XPM images
////@end XPM images

/*!
 * wxDuelDialog type definition
 */

IMPLEMENT_CLASS( wxDuelDialog, wxPanel )

/*!
 * wxDuelDialog event table definition
 */

BEGIN_EVENT_TABLE( wxDuelDialog, wxPanel )

////@begin wxDuelDialog event table entries
    EVT_TEXT_ENTER( CombatMensajeTextCtrlID, wxDuelDialog::OnCombatmensajetextctrlidEnter )

    EVT_BUTTON( PasarButtonID, wxDuelDialog::OnPasarbuttonidClick )

////@end wxDuelDialog event table entries

END_EVENT_TABLE()

/*!
 * wxDuelDialog constructors
 */

wxDuelDialog::wxDuelDialog( )
{
}

wxDuelDialog::wxDuelDialog( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

/*!
 * wxDuelDialog creator
 */

bool wxDuelDialog::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxDuelDialog member initialisation
    fgsmain = NULL;
    fgschild = NULL;
    fgsleft = NULL;
    OpponentStaticText = NULL;
    OpponentLFStaticText = NULL;
    CardStaticBitmap = NULL;
    MensajesTextCtrl = NULL;
    MensajeTextCtrl = NULL;
    PlayerStaticText = NULL;
    PlayerLFStaticText = NULL;
    PasarButton = NULL;
    fgscenter = NULL;
    fgsright = NULL;
    fgsopptbl = NULL;
    OppDeckCardStaticBitmap = NULL;
    OppGraveCardStaticBitmap = NULL;
    OppDeckCard2StaticBitmap = NULL;
    OppGraveCard2StaticBitmap = NULL;
    fgsplayertbl = NULL;
    PlayerDeckCard2StaticBitmap = NULL;
    PlayerGraveCard2StaticBitmap = NULL;
    PlayerDeckCardStaticBitmap = NULL;
    PlayerGraveCardStaticBitmap = NULL;
////@end wxDuelDialog member initialisation

////@begin wxDuelDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end wxDuelDialog creation
    return TRUE;
}

/*!
 * Control creation for wxDuelDialog
 */

void wxDuelDialog::CreateControls()
{    
////@begin wxDuelDialog content construction

    wxDuelDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    fgsmain = item2;
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(1, 3, 0, 2);
    fgschild = item3;
    item3->AddGrowableRow(0);
    item3->AddGrowableCol(2);
    item2->Add(item3, 1, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(4, 1, 5, 0);
    fgsleft = item4;
    item4->AddGrowableRow(2);
    item4->AddGrowableCol(0);
    item3->Add(item4, 1, wxALIGN_LEFT|wxGROW|wxALL, 0);

    wxFlexGridSizer* item5 = new wxFlexGridSizer(2, 2, 2, 2);
    item4->Add(item5, 0, wxALIGN_RIGHT|wxALIGN_TOP|wxALL, 0);

    wxStaticText* item6 = new wxStaticText( item1, wxID_STATIC, _("Oponente:"), wxDefaultPosition, wxDefaultSize, 0 );
    item5->Add(item6, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxStaticText* item7 = new wxStaticText( item1, OpponentStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    OpponentStaticText = item7;
    item5->Add(item7, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxStaticText* item8 = new wxStaticText( item1, wxID_STATIC, _("Vida:"), wxDefaultPosition, wxDefaultSize, 0 );
    item5->Add(item8, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxStaticText* item9 = new wxStaticText( item1, OpponentLFStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    OpponentLFStaticText = item9;
    item5->Add(item9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxBitmap item10Bitmap(wxNullBitmap);
    wxStaticBitmap* item10 = new wxStaticBitmap( item1, BigCardStaticBitmapID, item10Bitmap, wxDefaultPosition, wxSize(169, 225), 0 );
    CardStaticBitmap = item10;
    item4->Add(item10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item11 = new wxFlexGridSizer(2, 1, 2, 0);
    item11->AddGrowableRow(0);
    item11->AddGrowableCol(0);
    item4->Add(item11, 1, wxALIGN_CENTER_HORIZONTAL|wxGROW|wxALL, 0);

    wxTextCtrl* item12 = new wxTextCtrl( item1, CombatMensajesTextCtrl, _T(""), wxDefaultPosition, wxSize(169, 120), wxTE_MULTILINE|wxTE_READONLY|wxTE_LINEWRAP|wxTE_WORDWRAP );
    MensajesTextCtrl = item12;
    item11->Add(item12, 1, wxALIGN_RIGHT|wxGROW|wxALL, 0);

    wxTextCtrl* item13 = new wxTextCtrl( item1, CombatMensajeTextCtrlID, _T(""), wxDefaultPosition, wxSize(169, -1), 0 );
    MensajeTextCtrl = item13;
    item11->Add(item13, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item14 = new wxFlexGridSizer(2, 1, 5, 2);
    item4->Add(item14, 0, wxALIGN_RIGHT|wxALIGN_TOP|wxALL, 0);

    wxFlexGridSizer* item15 = new wxFlexGridSizer(2, 2, 2, 2);
    item14->Add(item15, 0, wxALIGN_RIGHT|wxALIGN_TOP|wxALL, 0);

    wxStaticText* item16 = new wxStaticText( item1, wxID_STATIC, _("Jugador:"), wxDefaultPosition, wxDefaultSize, 0 );
    item15->Add(item16, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxStaticText* item17 = new wxStaticText( item1, PlayerStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    PlayerStaticText = item17;
    item15->Add(item17, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxStaticText* item18 = new wxStaticText( item1, wxID_STATIC, _("Vida:"), wxDefaultPosition, wxDefaultSize, 0 );
    item15->Add(item18, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxStaticText* item19 = new wxStaticText( item1, PlayerLFStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    PlayerLFStaticText = item19;
    item15->Add(item19, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 0);

    wxButton* item20 = new wxButton( item1, PasarButtonID, _("Pasar"), wxDefaultPosition, wxDefaultSize, 0 );
    PasarButton = item20;
    item14->Add(item20, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item21 = new wxFlexGridSizer(1, 1, 0, 0);
    fgscenter = item21;
    item21->AddGrowableRow(0);
    item21->AddGrowableCol(0);
    item3->Add(item21, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item22 = new wxFlexGridSizer(2, 1, 5, 0);
    fgsright = item22;
    item22->AddGrowableRow(0);
    item22->AddGrowableRow(1);
    item22->AddGrowableCol(0);
    item3->Add(item22, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item23 = new wxFlexGridSizer(1, 3, 0, 5);
    fgsopptbl = item23;
    item23->AddGrowableRow(0);
    item23->AddGrowableCol(1);
    item22->Add(item23, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item24 = new wxFlexGridSizer(2, 1, 2, 0);
    item24->AddGrowableCol(0);
    item23->Add(item24, 1, wxALIGN_LEFT|wxGROW|wxALL, 0);

    wxBitmap item25Bitmap(wxNullBitmap);
    wxStaticBitmap* item25 = new wxStaticBitmap( item1, OppDeckCardStaticBitmapID, item25Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    OppDeckCardStaticBitmap = item25;
    item24->Add(item25, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBitmap item26Bitmap(wxNullBitmap);
    wxStaticBitmap* item26 = new wxStaticBitmap( item1, OppGraveCardStaticBitmapID, item26Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    OppGraveCardStaticBitmap = item26;
    item24->Add(item26, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item27 = new wxFlexGridSizer(2, 1, 2, 0);
    item27->AddGrowableRow(1);
    item27->AddGrowableCol(0);
    item23->Add(item27, 1, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item28 = new wxFlexGridSizer(1, 0, 0, 0);
    item28->AddGrowableRow(0);
    item27->Add(item28, 1, wxGROW|wxALIGN_TOP|wxALL, 0);

    wxFlexGridSizer* item29 = new wxFlexGridSizer(1, 0, 0, 0);
    item29->AddGrowableRow(0);
    item27->Add(item29, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item30 = new wxFlexGridSizer(2, 1, 2, 0);
    item30->AddGrowableCol(0);
    item23->Add(item30, 1, wxALIGN_LEFT|wxGROW|wxALL, 0);

    wxBitmap item31Bitmap(wxNullBitmap);
    wxStaticBitmap* item31 = new wxStaticBitmap( item1, OppDeckCard2StaticBitmapID, item31Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    OppDeckCard2StaticBitmap = item31;
    item30->Add(item31, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBitmap item32Bitmap(wxNullBitmap);
    wxStaticBitmap* item32 = new wxStaticBitmap( item1, OppGraveCard2StaticBitmapID, item32Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    OppGraveCard2StaticBitmap = item32;
    item30->Add(item32, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item33 = new wxFlexGridSizer(1, 3, 0, 5);
    fgsplayertbl = item33;
    item33->AddGrowableRow(0);
    item33->AddGrowableCol(1);
    item22->Add(item33, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item34 = new wxFlexGridSizer(2, 1, 2, 0);
    item34->AddGrowableCol(0);
    item33->Add(item34, 1, wxALIGN_LEFT|wxGROW|wxALL, 0);

    wxBitmap item35Bitmap(wxNullBitmap);
    wxStaticBitmap* item35 = new wxStaticBitmap( item1, PlayerDeckCard2StaticBitmapID, item35Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    PlayerDeckCard2StaticBitmap = item35;
    item34->Add(item35, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBitmap item36Bitmap(wxNullBitmap);
    wxStaticBitmap* item36 = new wxStaticBitmap( item1, PlayerGraveCard2StaticBitmapID, item36Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    PlayerGraveCard2StaticBitmap = item36;
    item34->Add(item36, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item37 = new wxFlexGridSizer(2, 1, 2, 0);
    item37->AddGrowableRow(1);
    item37->AddGrowableCol(0);
    item33->Add(item37, 1, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item38 = new wxFlexGridSizer(1, 0, 0, 0);
    item38->AddGrowableRow(0);
    item37->Add(item38, 1, wxGROW|wxALIGN_TOP|wxALL, 0);

    wxFlexGridSizer* item39 = new wxFlexGridSizer(1, 0, 0, 0);
    item39->AddGrowableRow(0);
    item37->Add(item39, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item40 = new wxFlexGridSizer(2, 1, 2, 0);
    item40->AddGrowableCol(0);
    item33->Add(item40, 1, wxALIGN_LEFT|wxGROW|wxALL, 0);

    wxBitmap item41Bitmap(wxNullBitmap);
    wxStaticBitmap* item41 = new wxStaticBitmap( item1, PlayerDeckCardStaticBitmapID, item41Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    PlayerDeckCardStaticBitmap = item41;
    item40->Add(item41, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBitmap item42Bitmap(wxNullBitmap);
    wxStaticBitmap* item42 = new wxStaticBitmap( item1, PlayerGraveCardStaticBitmapID, item42Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    PlayerGraveCardStaticBitmap = item42;
    item40->Add(item42, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

////@end wxDuelDialog content construction
}

/*!
 * wxEVT_COMMAND_TEXT_ENTER event handler for CombatMensajeTextCtrlID
 */

void wxDuelDialog::OnCombatmensajetextctrlidEnter( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for PasarButtonID
 */

void wxDuelDialog::OnPasarbuttonidClick( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * Should we show tooltips?
 */

bool wxDuelDialog::ShowToolTips()
{
    return TRUE;
}

void wxDuelDialog::ProcessGameStart(wxString name,wxInt32 deckvalue,wxInt32 rank)
{
  m_TEDProtocol->ChatExit();
  m_TEDProtocol->SetOpponent(name,deckvalue,rank);
  OpponentStaticText->SetLabel(name);
  m_TEDProtocol->GameStart();
}


