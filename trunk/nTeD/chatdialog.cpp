/////////////////////////////////////////////////////////////////////////////
// Name:        chatdialog.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/14/04 19:05:21
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "chatdialog.h"
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

#include "chatdialog.h"

////@begin XPM images
////@end XPM images

/*!
 * wxChatDialog type definition
 */

IMPLEMENT_CLASS( wxChatDialog, wxPanel )

/*!
 * wxChatDialog event table definition
 */

BEGIN_EVENT_TABLE( wxChatDialog, wxPanel )

////@begin wxChatDialog event table entries
    EVT_BUTTON( EnviarButtonID, wxChatDialog::OnEnviarbuttonClick )

////@end wxChatDialog event table entries

END_EVENT_TABLE()

/*!
 * wxChatDialog constructors
 */

wxChatDialog::wxChatDialog( )
{
}

wxChatDialog::wxChatDialog( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

/*!
 * wxChatDialog creator
 */

bool wxChatDialog::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxChatDialog member initialisation
    MensajesTextCtrl = NULL;
    MensajeTextCtrl = NULL;
    EnviarButton = NULL;
    UsuariosListCtrl = NULL;
    CanalesListCtrl = NULL;
////@end wxChatDialog member initialisation

////@begin wxChatDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end wxChatDialog creation
    UsuariosListCtrl->SetSizeHints(200,100);
    CanalesListCtrl->SetSizeHints(200,100);
    Layout();

    return TRUE;
}

/*!
 * Control creation for wxChatDialog
 */

void wxChatDialog::CreateControls()
{    
////@begin wxChatDialog content construction

    wxChatDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(1, 2, 0, 5);
    item3->AddGrowableRow(0);
    item3->AddGrowableCol(0);
    item2->Add(item3, 1, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 7);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(2, 1, 5, 0);
    item4->AddGrowableRow(0);
    item4->AddGrowableCol(0);
    item3->Add(item4, 1, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 0);

    wxTextCtrl* item5 = new wxTextCtrl;
    item5->Create( item1, MensajesTextCtrlID, _T(""), wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE );
    MensajesTextCtrl = item5;
    item4->Add(item5, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item6 = new wxFlexGridSizer(1, 2, 0, 5);
    item6->AddGrowableRow(0);
    item6->AddGrowableCol(0);
    item4->Add(item6, 1, wxGROW|wxALIGN_BOTTOM|wxALL, 0);

    wxTextCtrl* item7 = new wxTextCtrl;
    item7->Create( item1, MensajeTextCtrlID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    MensajeTextCtrl = item7;
    item6->Add(item7, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item8 = new wxButton;
    item8->Create( item1, EnviarButtonID, _("Enviar"), wxDefaultPosition, wxDefaultSize, 0 );
    EnviarButton = item8;
    item8->SetDefault();
    item6->Add(item8, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxBoxSizer* item9 = new wxBoxSizer(wxVERTICAL);
    item3->Add(item9, 1, wxALIGN_RIGHT|wxGROW|wxALL, 0);

    wxListCtrl* item10 = new wxListCtrl;
    item10->Create( item1, UsuariosListCtrlID, wxDefaultPosition, wxSize(200, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES );
    UsuariosListCtrl = item10;
    item9->Add(item10, 1, wxALIGN_RIGHT|wxALL, 0);

    item9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxListCtrl* item12 = new wxListCtrl;
    item12->Create( item1, CanalesListCtrlID, wxDefaultPosition, wxSize(200, 100), 0 );
    CanalesListCtrl = item12;
    item9->Add(item12, 0, wxALIGN_RIGHT|wxALL, 0);

////@end wxChatDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool wxChatDialog::ShowToolTips()
{
    return TRUE;
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for EnviarButton
 */

void wxChatDialog::OnEnviarbuttonClick( wxCommandEvent& event )
{
    // Insert custom code here
    UsuariosListCtrl->InsertColumn(0,_("Nombre"));
    UsuariosListCtrl->InsertColumn(1,_("Valor"));
    UsuariosListCtrl->InsertColumn(2,_("Ranking"));
    UsuariosListCtrl->InsertItem(0,_T("0,0"));
    UsuariosListCtrl->SetItem(0,1,_T("0,1"));
    UsuariosListCtrl->SetItem(0,2,_T("0,2"));
    UsuariosListCtrl->InsertItem(1,_T("1,0"));
    UsuariosListCtrl->SetItem(1,1,_T("1,1"));
    UsuariosListCtrl->SetItem(1,2,_T("1,2"));
    UsuariosListCtrl->InsertItem(2,_T("2,0"));
    UsuariosListCtrl->SetItem(2,1,_T("2,1"));
    UsuariosListCtrl->SetItem(2,2,_T("2,2"));
    UsuariosListCtrl->SetColumnWidth(0,wxLIST_AUTOSIZE);
    UsuariosListCtrl->SetColumnWidth(1,wxLIST_AUTOSIZE);
    UsuariosListCtrl->SetColumnWidth(2,wxLIST_AUTOSIZE);
    UsuariosListCtrl->InsertItem(3,_T("Nombre largo"));
    UsuariosListCtrl->SetItem(3,1,_T("3,1"));
    UsuariosListCtrl->SetItem(3,2,_T("3,2"));
    event.Skip();
}


