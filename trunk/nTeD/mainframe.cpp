/////////////////////////////////////////////////////////////////////////////
// Name:        mainframe.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/14/04 16:36:40
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "mainframe.h"
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

#include "mainframe.h"

////@begin XPM images
////@end XPM images

/*!
 * wxMainFrame type definition
 */

IMPLEMENT_CLASS( wxMainFrame, wxFrame )

/*!
 * wxMainFrame event table definition
 */

BEGIN_EVENT_TABLE( wxMainFrame, wxFrame )

////@begin wxMainFrame event table entries
    EVT_SIZE( wxMainFrame::OnSize )

    EVT_MENU( ConectarTool, wxMainFrame::OnConectartoolClick )

    EVT_MENU( ChatTool, wxMainFrame::OnChattoolClick )

    EVT_MENU( BarajasTool, wxMainFrame::OnBarajastoolClick )

    EVT_MENU( InfoTool, wxMainFrame::OnInfotoolClick )

    EVT_MENU( PrefTool, wxMainFrame::OnPreftoolClick )

////@end wxMainFrame event table entries

END_EVENT_TABLE()

/*!
 * wxMainFrame constructors
 */

wxMainFrame::wxMainFrame( )
{
}

wxMainFrame::wxMainFrame( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create( parent, id, caption, pos, size, style );
}

/*!
 * wxMainFrame creator
 */

bool wxMainFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxMainFrame member initialisation
    MainToolBar = NULL;
////@end wxMainFrame member initialisation

////@begin wxMainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end wxMainFrame creation
    m_LoginWnd=new wxLoginDialog(this);
    m_LoginWnd->Hide();
    m_ChatWnd=new wxChatDialog(this);
    m_ChatWnd->Hide();
    m_ActiveWnd=m_LoginWnd;
    m_mainsizer=(wxFlexGridSizer*)GetSizer();
    m_mainsizer->Add(m_ActiveWnd, 1, wxALIGN_LEFT|wxEXPAND|wxALL);
    m_ActiveWnd->Show();
    Layout();


    return TRUE;
}

/*!
 * Control creation for wxMainFrame
 */

void wxMainFrame::CreateControls()
{    
////@begin wxMainFrame content construction

    wxMainFrame* item1 = this;

    wxToolBar* item2 = new wxToolBar;
    item2->Create( item1, MainToolBarID, wxDefaultPosition, wxSize(200, -1), wxTB_FLAT|wxTB_HORIZONTAL );
    MainToolBar = item2;
    item2->SetToolBitmapSize(wxSize(32, 32));
    item2->AddSeparator();

    wxBitmap item4Bitmap(_T("conectar.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(ConectarTool, _("Conectar"), item4Bitmap, _("Conectar"), wxITEM_CHECK);

    item2->AddSeparator();

    wxBitmap item6Bitmap(_T("btn_irc.xpm"), wxBITMAP_TYPE_XPM);
    item2->AddTool(ChatTool, _("Canales"), item6Bitmap, _("Canales"), wxITEM_CHECK);

    wxBitmap item7Bitmap(_T("globes_blue_p6.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(BarajasTool, _("Barajas"), item7Bitmap, _("Barajas"), wxITEM_CHECK);

    item2->AddSeparator();

    wxBitmap item9Bitmap(_T("Info Balloon_p08.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(InfoTool, _("Información"), item9Bitmap, _("Información"), wxITEM_CHECK);

    wxBitmap item10Bitmap(_T("btn_preferences.xpm"), wxBITMAP_TYPE_XPM);
    item2->AddTool(PrefTool, _("Preferencias"), item10Bitmap, _("Preferencias"), wxITEM_CHECK);

    item2->AddSeparator();

    wxBitmap item12Bitmap(_T("Log Off_p07.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(SalirTool, _("Salir"), item12Bitmap, _("Salir"), wxITEM_CHECK);

    item2->Realize();
    item1->SetToolBar(item2);

    wxFlexGridSizer* item13 = new wxFlexGridSizer(1, 1, 0, 0);
    item13->AddGrowableRow(0);
    item13->AddGrowableCol(0);
    item1->SetSizer(item13);
    item1->SetAutoLayout(TRUE);

////@end wxMainFrame content construction
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ConectarTool
 */

void wxMainFrame::OnConectartoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ChatTool
 */

void wxMainFrame::OnChattoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for BarajasTool
 */

void wxMainFrame::OnBarajastoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for InfoTool
 */

void wxMainFrame::OnInfotoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for PrefTool
 */

void wxMainFrame::OnPreftoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * Should we show tooltips?
 */

bool wxMainFrame::ShowToolTips()
{
    return TRUE;
}
/*!
 * wxEVT_SIZE event handler for MainFrame
 */

void wxMainFrame::OnSize( wxSizeEvent& event )
{
    // Insert custom code here
    Refresh();
    event.Skip();
}


