/////////////////////////////////////////////////////////////////////////////
// Name:        mainframe.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     02/23/04 15:40:11
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "mainframe.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

////@begin includes
#include "wx/wx.h"
#include "wx/toolbar.h"
////@end includes

#include "mainframe.h"

////@begin XPM images
////@end XPM images

/*!
 * MainFrame type definition
 */

IMPLEMENT_CLASS( MainFrame, wxFrame )

/*!
 * MainFrame event table definition
 */

BEGIN_EVENT_TABLE( MainFrame, wxFrame )

////@begin MainFrame event table entries
////@end MainFrame event table entries

END_EVENT_TABLE()

/*!
 * MainFrame constructors
 */

MainFrame::MainFrame( )
{
}

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create( parent, id, caption, pos, size, style );
}

/*!
 * MainFrame creator
 */

bool MainFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin MainFrame member initialisation
////@end MainFrame member initialisation

////@begin MainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end MainFrame creation
    return TRUE;
}

/*!
 * Control creation for MainFrame
 */

void MainFrame::CreateControls()
{    
////@begin MainFrame content construction

    MainFrame* item1 = this;

    wxToolBar* item2 = new wxToolBar( item1, MainToolBar, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxNO_BORDER );
    item2->SetToolBitmapSize(wxSize(32, 32));
    item2->AddSeparator();

    wxBitmap item4Bitmap(_T("conectar.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(ConectarTool, CONECTAR, item4Bitmap, _T(""), wxITEM_NORMAL);

    item2->AddSeparator();

    wxBitmap item6Bitmap;
    item2->AddTool(ChatTool, CANALES, item6Bitmap, _T(""), wxITEM_NORMAL);

    wxBitmap item7Bitmap;
    item2->AddTool(BarajasTool, BARAJAS, item7Bitmap, _T(""), wxITEM_NORMAL);

    item2->AddSeparator();

    wxBitmap item9Bitmap;
    item2->AddTool(InfoTool, INFO, item9Bitmap, _T(""), wxITEM_NORMAL);

    wxBitmap item10Bitmap(_T("preferencias.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(PrefTool, PREFERENCIAS, item10Bitmap, _T(""), wxITEM_NORMAL);

    item2->Realize();
    item1->SetToolBar(item2);

////@end MainFrame content construction
}

/*!
 * Should we show tooltips?
 */

bool MainFrame::ShowToolTips()
{
    return TRUE;
}
