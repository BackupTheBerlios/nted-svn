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
    EVT_CLOSE( wxMainFrame::OnCloseWindow )
    EVT_SIZE( wxMainFrame::OnSize )

    EVT_MENU( ConectarTool, wxMainFrame::OnConectartoolClick )

    EVT_MENU( ChatTool, wxMainFrame::OnChattoolClick )

    EVT_MENU( BarajasTool, wxMainFrame::OnBarajastoolClick )

    EVT_MENU( InfoTool, wxMainFrame::OnInfotoolClick )

    EVT_MENU( PrefTool, wxMainFrame::OnPreftoolClick )

    EVT_MENU( SalirTool, wxMainFrame::OnSalirtoolClick )

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
    m_ChatWnd->SetSizeHints(626,348);
    m_ChatWnd->Layout();
    m_ChatWnd->Hide();
    m_ActiveWnd=m_LoginWnd;
    m_mainsizer=(wxFlexGridSizer*)GetSizer();
    m_mainsizer->Add(m_ActiveWnd, 1, wxALIGN_LEFT|wxEXPAND|wxALL);
    m_ActiveWnd->Show();
    Layout();
    m_TEDProtocol=new TEDProtocol();
    m_LoginWnd->m_TEDProtocol=m_TEDProtocol;

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
    item2->Create( item1, MainToolBarID, wxDefaultPosition, wxSize(200, -1), wxTB_FLAT|wxTB_HORIZONTAL|wxTB_TEXT|wxTB_NODIVIDER );
    MainToolBar = item2;
    item2->SetToolBitmapSize(wxSize(32, 32));
    item2->AddSeparator();

    wxBitmap item4Bitmap(_T("conectar.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(ConectarTool, _("Conectar"), item4Bitmap, _("Conectar"), wxITEM_NORMAL);

    item2->AddSeparator();

    wxBitmap item6Bitmap(_T("btn_irc.xpm"), wxBITMAP_TYPE_XPM);
    item2->AddTool(ChatTool, _("Canales"), item6Bitmap, _("Canales"), wxITEM_RADIO);

    wxBitmap item7Bitmap(_T("globes_blue_p6.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(BarajasTool, _("Barajas"), item7Bitmap, _("Barajas"), wxITEM_RADIO);

    wxBitmap item8Bitmap(_T("Info Balloon_p08.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(InfoTool, _("Información"), item8Bitmap, _("Información"), wxITEM_RADIO);

    wxBitmap item9Bitmap(_T("btn_preferences.xpm"), wxBITMAP_TYPE_XPM);
    item2->AddTool(PrefTool, _("Preferencias"), item9Bitmap, _("Preferencias"), wxITEM_RADIO);

    item2->AddSeparator();

    wxBitmap item11Bitmap(_T("Log Off_p07.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(SalirTool, _("Salir"), item11Bitmap, _("Salir"), wxITEM_NORMAL);

    item2->Realize();
    item1->SetToolBar(item2);

    wxFlexGridSizer* item12 = new wxFlexGridSizer(1, 1, 0, 0);
    item12->AddGrowableRow(0);
    item12->AddGrowableCol(0);
    item1->SetSizer(item12);
    item1->SetAutoLayout(TRUE);

////@end wxMainFrame content construction
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ConectarTool
 */

void wxMainFrame::OnConectartoolClick( wxCommandEvent& event )
{
    // Insert custom code here
//    UpdateToolbar(ConectarTool);
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ChatTool
 */

void wxMainFrame::OnChattoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    UpdateToolbar(ChatTool);
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for BarajasTool
 */

void wxMainFrame::OnBarajastoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    UpdateToolbar(BarajasTool);
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for InfoTool
 */

void wxMainFrame::OnInfotoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    UpdateToolbar(InfoTool);
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for PrefTool
 */

void wxMainFrame::OnPreftoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    UpdateToolbar(PrefTool);
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for SalirTool
 */

void wxMainFrame::OnSalirtoolClick( wxCommandEvent& event )
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

void wxMainFrame::UpdateToolbar(int id)
{
  m_ActiveWnd->Hide();
  m_mainsizer->Detach(m_ActiveWnd);
  switch (id)
  {
    case ChatTool:
    {
      m_ActiveWnd=m_ChatWnd;
      break;
    }
    case BarajasTool:
    {
      if ((m_ActiveWnd)!=(m_ChatWnd))
      {
      }
      break;
    }
    case InfoTool:
    {
      if ((m_ActiveWnd)!=(m_ChatWnd))
      {
      }
      break;
    }
    case PrefTool:
    {
      if ((m_ActiveWnd)!=(m_ChatWnd))
      {
      }
      break;
    }
  }
  m_mainsizer->Add(m_ActiveWnd, 1, wxALIGN_LEFT|wxEXPAND|wxALL);
  m_ActiveWnd->Show();
  Layout();
//    MainToolBar->FindById(ConectarTool)->Toggle(FALSE);
    MainToolBar->FindById(ChatTool)->Toggle(FALSE);
    MainToolBar->FindById(BarajasTool)->Toggle(FALSE);
    MainToolBar->FindById(InfoTool)->Toggle(FALSE);
    MainToolBar->FindById(PrefTool)->Toggle(FALSE);
//    MainToolBar->FindById(SalirTool)->Toggle(FALSE);
    MainToolBar->FindById(id)->Toggle(TRUE);
    return;
}

/*!
 * wxEVT_CLOSE_WINDOW event handler for MainFrame
 */

void wxMainFrame::OnCloseWindow( wxCloseEvent& event )
{
    // Insert custom code here
    event.Skip();
}

void wxMainFrame::OnIdle(wxIdleEvent& event)
{
  wxString msg;
  
//  ::wxGetApp().m_critsec.Enter();
  while ((msg=m_TEDProtocol->GetMessage())!=wxEmptyString)
  {
    ::wxMessageBox(msg,_("Mensaje del Servidor"));
  }
//  ::wxGetApp().m_critsec.Leave();
  event.Skip();
}

