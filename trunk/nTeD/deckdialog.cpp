/////////////////////////////////////////////////////////////////////////////
// Name:        deckdialog.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     05/03/04 19:45:26
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "deckdialog.h"
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

#include "deckdialog.h"

////@begin XPM images
////@end XPM images

/*!
 * wxDeckDialog type definition
 */

IMPLEMENT_CLASS( wxDeckDialog, wxPanel )

/*!
 * wxDeckDialog event table definition
 */

BEGIN_EVENT_TABLE( wxDeckDialog, wxPanel )

////@begin wxDeckDialog event table entries
////@end wxDeckDialog event table entries

END_EVENT_TABLE()

/*!
 * wxDeckDialog constructors
 */

wxDeckDialog::wxDeckDialog( )
{
}

wxDeckDialog::wxDeckDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * wxDeckDialog creator
 */

bool wxDeckDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxDeckDialog member initialisation
    fgsmain = NULL;
    fgschild = NULL;
    fgsleft = NULL;
    ReserveListCtrl = NULL;
    fgscenter = NULL;
    fgscenterchild = NULL;
    CardStaticBitmap = NULL;
    fgsbuttons = NULL;
    fgsright = NULL;
////@end wxDeckDialog member initialisation

////@begin wxDeckDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end wxDeckDialog creation
    return TRUE;
}

/*!
 * Control creation for wxDeckDialog
 */

void wxDeckDialog::CreateControls()
{    
////@begin wxDeckDialog content construction

    wxDeckDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    fgsmain = item2;
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(1, 3, 0, 0);
    fgschild = item3;
    item3->AddGrowableRow(0);
    item3->AddGrowableCol(0);
    item3->AddGrowableCol(2);
    item2->Add(item3, 1, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(1, 1, 0, 0);
    fgsleft = item4;
    item4->AddGrowableRow(0);
    item4->AddGrowableCol(0);
    item3->Add(item4, 1, wxGROW|wxGROW|wxALL, 0);

    wxListCtrl* item5 = new wxListCtrl( item1, ReserveListCtrlID, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_NO_HEADER );
    ReserveListCtrl = item5;
    item4->Add(item5, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item6 = new wxFlexGridSizer(2, 1, 0, 0);
    fgscenter = item6;
    item6->AddGrowableRow(0);
    item6->AddGrowableCol(0);
    item3->Add(item6, 1, wxGROW|wxGROW|wxALL, 0);

    item6->Add(5, 5, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item8 = new wxFlexGridSizer(2, 1, 5, 0);
    fgscenterchild = item8;
    item6->Add(item8, 1, wxGROW|wxGROW|wxALL, 0);

    wxBitmap item9Bitmap;
    wxStaticBitmap* item9 = new wxStaticBitmap( item1, CardStaticBitmapID, item9Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    CardStaticBitmap = item9;
    item8->Add(item9, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item10 = new wxFlexGridSizer(0, 1, 0, 0);
    fgsbuttons = item10;
    item8->Add(item10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* item11 = new wxButton( item1, ID_BUTTON, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    item10->Add(item11, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item12 = new wxButton( item1, ID_BUTTON1, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    item10->Add(item12, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item13 = new wxButton( item1, ID_BUTTON2, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    item10->Add(item13, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item14 = new wxButton( item1, ID_BUTTON3, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    item10->Add(item14, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item15 = new wxButton( item1, ID_BUTTON4, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    item10->Add(item15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item16 = new wxFlexGridSizer(1, 1, 0, 0);
    fgsright = item16;
    item16->AddGrowableRow(0);
    item16->AddGrowableCol(0);
    item3->Add(item16, 1, wxGROW|wxGROW|wxALL, 0);

    wxListCtrl* item17 = new wxListCtrl( item1, ID_LISTCTRL1, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_NO_HEADER );
    item16->Add(item17, 1, wxGROW|wxGROW|wxALL, 0);

////@end wxDeckDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool wxDeckDialog::ShowToolTips()
{
    return TRUE;
}
