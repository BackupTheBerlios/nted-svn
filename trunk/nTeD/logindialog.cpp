/////////////////////////////////////////////////////////////////////////////
// Name:        logindialog.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     02/24/04 15:29:08
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "logindialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

////@begin includes
#include "wx/wx.h"
////@end includes

#include "logindialog.h"

////@begin XPM images
////@end XPM images

/*!
 * LoginDialog type definition
 */

IMPLEMENT_CLASS( LoginDialog, wxDialog )

/*!
 * LoginDialog event table definition
 */

BEGIN_EVENT_TABLE( LoginDialog, wxDialog )

////@begin LoginDialog event table entries
////@end LoginDialog event table entries

END_EVENT_TABLE()

/*!
 * LoginDialog constructors
 */

LoginDialog::LoginDialog( )
{
}

LoginDialog::LoginDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * LoginDialog creator
 */

bool LoginDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin LoginDialog member initialisation
////@end LoginDialog member initialisation

////@begin LoginDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end LoginDialog creation
    return TRUE;
}

/*!
 * Control creation for LoginDialog
 */

void LoginDialog::CreateControls()
{    
////@begin LoginDialog content construction

    LoginDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(3, 1, 0, 0);
    item3->AddGrowableRow(0);
    item3->AddGrowableRow(2);
    item3->AddGrowableCol(0);
    item2->Add(item3, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(1, 1, 0, 0);
    item4->AddGrowableRow(0);
    item4->AddGrowableCol(0);
    item3->Add(item4, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item5 = new wxFlexGridSizer(1, 3, 0, 0);
    item5->AddGrowableRow(0);
    item5->AddGrowableCol(0);
    item5->AddGrowableCol(2);
    item3->Add(item5, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item6 = new wxFlexGridSizer(1, 1, 0, 0);
    item6->AddGrowableRow(0);
    item6->AddGrowableCol(0);
    item5->Add(item6, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item7 = new wxFlexGridSizer(4, 1, 0, 0);
    item5->Add(item7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item8 = new wxFlexGridSizer(1, 2, 0, 0);
    item8->AddGrowableCol(0);
    item8->AddGrowableCol(1);
    item7->Add(item8, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item9 = new wxStaticText( item1, UsuarioStatic, _("Usuario:"), wxDefaultPosition, wxDefaultSize, 0 );
    item8->Add(item9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxTextCtrl* item10 = new wxTextCtrl( item1, UsuarioTextCtrl, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    item8->Add(item10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* item11 = new wxFlexGridSizer(1, 2, 0, 0);
    item11->AddGrowableCol(0);
    item11->AddGrowableCol(1);
    item7->Add(item11, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item12 = new wxStaticText( item1, ContrasenaStatic, _("Contraseña:"), wxDefaultPosition, wxDefaultSize, 0 );
    item11->Add(item12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxTextCtrl* item13 = new wxTextCtrl( item1, ContrasenaTextCtrl, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    item11->Add(item13, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    item7->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* item15 = new wxFlexGridSizer(1, 1, 0, 0);
    item15->AddGrowableRow(0);
    item15->AddGrowableCol(0);
    item7->Add(item15, 0, wxGROW|wxGROW|wxALL, 5);

    wxButton* item16 = new wxButton( item1, ConectarButton, CONECTAR, wxDefaultPosition, wxDefaultSize, 0 );
    item15->Add(item16, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item17 = new wxFlexGridSizer(1, 1, 0, 0);
    item17->AddGrowableRow(0);
    item17->AddGrowableCol(0);
    item5->Add(item17, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item18 = new wxFlexGridSizer(1, 1, 0, 0);
    item18->AddGrowableRow(0);
    item18->AddGrowableCol(0);
    item3->Add(item18, 0, wxGROW|wxGROW|wxALL, 5);

////@end LoginDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool LoginDialog::ShowToolTips()
{
    return TRUE;
}
