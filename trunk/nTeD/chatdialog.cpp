/////////////////////////////////////////////////////////////////////////////
// Name:        chatdialog.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     02/27/04 09:53:08
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "chatdialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

////@begin includes
#include "wx/wx.h"
#include "wx/listctrl.h"
////@end includes

#include "chatdialog.h"

////@begin XPM images
////@end XPM images

/*!
 * ChatDialog type definition
 */

IMPLEMENT_CLASS( ChatDialog, wxDialog )

/*!
 * ChatDialog event table definition
 */

BEGIN_EVENT_TABLE( ChatDialog, wxDialog )

////@begin ChatDialog event table entries
////@end ChatDialog event table entries

END_EVENT_TABLE()

/*!
 * ChatDialog constructors
 */

ChatDialog::ChatDialog( )
{
}

ChatDialog::ChatDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * ChatDialog creator
 */

bool ChatDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ChatDialog member initialisation
////@end ChatDialog member initialisation

////@begin ChatDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end ChatDialog creation
    return TRUE;
}

/*!
 * Control creation for ChatDialog
 */

void ChatDialog::CreateControls()
{    
////@begin ChatDialog content construction

    ChatDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(1, 2, 0, 5);
    item3->AddGrowableRow(0);
    item3->AddGrowableCol(0);
    item2->Add(item3, 1, wxGROW|wxGROW|wxALL, 7);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(2, 1, 5, 0);
    item4->AddGrowableRow(0);
    item4->AddGrowableCol(0);
    item3->Add(item4, 1, wxGROW|wxGROW|wxALL, 0);

    wxTextCtrl* item5 = new wxTextCtrl( item1, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    item4->Add(item5, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item6 = new wxFlexGridSizer(1, 2, 0, 5);
    item6->AddGrowableRow(0);
    item6->AddGrowableCol(0);
    item4->Add(item6, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxTextCtrl* item7 = new wxTextCtrl( item1, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    item6->Add(item7, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item8 = new wxButton( item1, EnviarButton, _("Enviar"), wxDefaultPosition, wxDefaultSize, 0 );
    item8->SetDefault();
    item6->Add(item8, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBoxSizer* item9 = new wxBoxSizer(wxVERTICAL);
    item3->Add(item9, 1, wxALIGN_CENTER_HORIZONTAL|wxGROW|wxALL, 0);

    wxListCtrl* item10 = new wxListCtrl( item1, ID_LISTCTRL, wxDefaultPosition, wxSize(100, 100), wxLC_LIST  );
    item9->Add(item10, 1, wxALIGN_RIGHT|wxALL, 0);

    item9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxListCtrl* item12 = new wxListCtrl( item1, ID_LISTCTRL1, wxDefaultPosition, wxSize(100, 100), 0 );
    item9->Add(item12, 0, wxALIGN_RIGHT|wxALL, 0);

////@end ChatDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool ChatDialog::ShowToolTips()
{
    return TRUE;
}
