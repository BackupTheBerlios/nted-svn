/////////////////////////////////////////////////////////////////////////////
// Name:        logindialog.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/07/04 14:06:17
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "logindialog.h"
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

#include "logindialog.h"

////@begin XPM images
////@end XPM images

/*!
 * wxLoginDialog type definition
 */

IMPLEMENT_CLASS( wxLoginDialog, wxPanel )

/*!
 * wxLoginDialog event table definition
 */

BEGIN_EVENT_TABLE( wxLoginDialog, wxPanel )

////@begin wxLoginDialog event table entries
    EVT_BUTTON( ConectarButtonID, wxLoginDialog::OnConectarbuttonClick )

////@end wxLoginDialog event table entries

END_EVENT_TABLE()

/*!
 * wxLoginDialog constructors
 */

wxLoginDialog::wxLoginDialog( )
{
}

wxLoginDialog::wxLoginDialog( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

/*!
 * wxLoginDialog creator
 */

bool wxLoginDialog::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxLoginDialog member initialisation
    UsuarioStatic = NULL;
    UsuarioTextCtrl = NULL;
    ContrasenaStatic = NULL;
    ContrasenaTextCtrl = NULL;
    ConectarButton = NULL;
////@end wxLoginDialog member initialisation

////@begin wxLoginDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end wxLoginDialog creation
    return TRUE;
}

/*!
 * Control creation for wxLoginDialog
 */

void wxLoginDialog::CreateControls()
{    
////@begin wxLoginDialog content construction

    wxLoginDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(3, 1, 0, 0);
    item3->AddGrowableRow(0);
    item3->AddGrowableRow(2);
    item3->AddGrowableCol(0);
    item2->Add(item3, 0, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 5);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(1, 1, 0, 0);
    item4->AddGrowableRow(0);
    item4->AddGrowableCol(0);
    item3->Add(item4, 0, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 5);

    wxFlexGridSizer* item5 = new wxFlexGridSizer(1, 3, 0, 0);
    item5->AddGrowableRow(0);
    item5->AddGrowableCol(0);
    item5->AddGrowableCol(2);
    item3->Add(item5, 0, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 5);

    wxFlexGridSizer* item6 = new wxFlexGridSizer(1, 1, 0, 0);
    item6->AddGrowableRow(0);
    item6->AddGrowableCol(0);
    item5->Add(item6, 0, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 5);

    wxFlexGridSizer* item7 = new wxFlexGridSizer(4, 1, 0, 0);
    item5->Add(item7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item8 = new wxFlexGridSizer(1, 2, 0, 0);
    item8->AddGrowableCol(0);
    item8->AddGrowableCol(1);
    item7->Add(item8, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item9 = new wxStaticText;
    item9->Create( item1, UsuarioStaticID, _("Usuario:"), wxDefaultPosition, wxDefaultSize, 0 );
    UsuarioStatic = item9;
    item8->Add(item9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxTextCtrl* item10 = new wxTextCtrl;
    item10->Create( item1, UsuarioTextCtrlID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    UsuarioTextCtrl = item10;
    item8->Add(item10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* item11 = new wxFlexGridSizer(1, 2, 0, 0);
    item11->AddGrowableCol(0);
    item11->AddGrowableCol(1);
    item7->Add(item11, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item12 = new wxStaticText;
    item12->Create( item1, ContrasenaStaticID, _("Contraseña:"), wxDefaultPosition, wxDefaultSize, 0 );
    ContrasenaStatic = item12;
    item11->Add(item12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxTextCtrl* item13 = new wxTextCtrl;
    item13->Create( item1, ContrasenaTextCtrlID, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    ContrasenaTextCtrl = item13;
    item11->Add(item13, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    item7->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* item15 = new wxFlexGridSizer(1, 1, 0, 0);
    item15->AddGrowableRow(0);
    item15->AddGrowableCol(0);
    item7->Add(item15, 0, wxGROW|wxGROW|wxALL, 5);

    wxButton* item16 = new wxButton;
    item16->Create( item1, ConectarButtonID, _("Conectar"), wxDefaultPosition, wxDefaultSize, 0 );
    ConectarButton = item16;
    item16->SetDefault();
    item15->Add(item16, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item17 = new wxFlexGridSizer(1, 1, 0, 0);
    item17->AddGrowableRow(0);
    item17->AddGrowableCol(0);
    item5->Add(item17, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item18 = new wxFlexGridSizer(1, 1, 0, 0);
    item18->AddGrowableRow(0);
    item18->AddGrowableCol(0);
    item3->Add(item18, 0, wxGROW|wxGROW|wxALL, 5);

////@end wxLoginDialog content construction
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ConectarButton
 */

void wxLoginDialog::OnConectarbuttonClick( wxCommandEvent& event )
{
    // Insert custom code here
    if ((UsuarioTextCtrl->GetValue()=="") || (ContrasenaTextCtrl->GetValue()==""))
    {
        ::wxMessageBox(_("Escribe tu nombre y clave."),_("Titanes"),wxOK|wxICON_ERROR);
        event.Skip();
        return;
    }
    ConectarButton->Disable();
//    ::wxLogFatalError(_("Antes del IsConnected"));
//    ::wxSafeShowMessage(_("Titanes"),_("Antes del IsConnected"));
    if (m_TEDProtocol->IsConnected()==FALSE)
    {
//      ::wxLogFatalError(_("Antes del Connect"));
//      ::wxSafeShowMessage(_("Titanes"),_("Antes del Connect"));
      m_TEDProtocol->Connect();
      if (m_TEDProtocol->IsConnected()==FALSE)
      {
        ::wxSafeShowMessage(_("Titanes"),_("No se puede conectar al servidor.\nInténtalo de nuevo más tarde."));
        ConectarButton->Enable();
        event.Skip();
        return;
      }
    }
//    ::wxLogFatalError(_("Antes del Login"));
//    ::wxSafeShowMessage(_("Titanes"),_("Antes del Login"));
    m_TEDProtocol->Login(UsuarioTextCtrl->GetValue(),ContrasenaTextCtrl->GetValue());
//    ::wxLogFatalError(_("Despues del Login"));
//    ::wxSafeShowMessage(_("Titanes"),_("Despues del Login"));
    if (m_TEDProtocol->IsLogged()==FALSE)
    {
      ConectarButton->Enable();
    }
    ((wxMainFrame *)GetParent())->UpdateToolbar(ChatTool);
    ((wxMainFrame *)GetParent())->m_ChatWnd->SetChannelNames();
    event.Skip();
}

/*!
 * Should we show tooltips?
 */

bool wxLoginDialog::ShowToolTips()
{
    return TRUE;
}
