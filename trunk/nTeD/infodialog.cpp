/////////////////////////////////////////////////////////////////////////////
// Name:        infodialog.cpp
// Purpose:     
// Author:      Kintups
// Modified by: 
// Created:     04/28/04 12:52:30
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "infodialog.h"
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

#include "infodialog.h"

////@begin XPM images
////@end XPM images

/*!
 * wxInfoDialog type definition
 */

IMPLEMENT_CLASS( wxInfoDialog, wxPanel )

/*!
 * wxInfoDialog event table definition
 */

BEGIN_EVENT_TABLE( wxInfoDialog, wxPanel )

////@begin wxInfoDialog event table entries
////@end wxInfoDialog event table entries

END_EVENT_TABLE()

/*!
 * wxInfoDialog constructors
 */

wxInfoDialog::wxInfoDialog( )
{
}

wxInfoDialog::wxInfoDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * wxInfoDialog creator
 */

bool wxInfoDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin wxInfoDialog member initialisation
    InfoHtmlWindow = NULL;
    LogTextCtrl = NULL;
////@end wxInfoDialog member initialisation

////@begin wxInfoDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end wxInfoDialog creation
    LogTextCtrl->SetSizeHints(200,100,1600,150);
    Layout();

    return TRUE;
}

/*!
 * Control creation for wxInfoDialog
 */

void wxInfoDialog::CreateControls()
{    
////@begin wxInfoDialog content construction

    wxInfoDialog* item1 = this;

    wxFlexGridSizer* item2 = new wxFlexGridSizer(1, 1, 0, 0);
    item2->AddGrowableRow(0);
    item2->AddGrowableCol(0);
    item1->SetSizer(item2);
    item1->SetAutoLayout(TRUE);

    wxFlexGridSizer* item3 = new wxFlexGridSizer(0, 1, 5, 0);
    item3->AddGrowableCol(0);
    item2->Add(item3, 0, wxGROW|wxGROW|wxALL|wxADJUST_MINSIZE, 5);

    wxHtmlWindow* item4 = new wxHtmlWindow;
    item4->Create( item1, InfoHtmlWindowID, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER );
    InfoHtmlWindow = item4;
    item4->SetPage(wxT("<center><font size=5>Titanes -=[ El Destierro ]=-</font></center>
<p>
Titanes, el juego de cartas coleccionables online multiusuario y gratuíto, es un proyecto desarrollado conjuntamente por personas de diferentes países.
<p>
<strong>Equipo de desarrollo:</strong><br>
<ul>
<li>Attradis (programación del cliente)</li>
<li>JJpRiVaTe (programación del servidor)</li>
<li><a href=mailto:kintups@titanes.com>Kintups</a> (seguridad del servidor e integridad del protocolo)</li>
<li>Loko (mantenimiento web)</li>
<li>Mariana (dibujante)</li>
<li>Seln (diseño gráfico y coordinación, mantenimiento web)</li>
<li>YaW (jugabilidad y diseño, scripts para el desarrollo, coordinación)</li>
</ul>
<p>
El equipo de desarrollo quiere agradecer su interés a todos los que han seguido y siguen el desarrollo del proyecto, y colaboran con sus emails a los coordinadores y sus comentarios en los foros.
<p>
<a href=http://www.titanesed.ya.st>http://www.titanesed.ya.st></a>
"));
    item3->Add(item4, 0, wxGROW|wxGROW|wxALL, 0);

    wxTextCtrl* item5 = new wxTextCtrl;
    item5->Create( item1, LogTextCtrlID, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
    LogTextCtrl = item5;
    item3->Add(item5, 0, wxGROW|wxGROW|wxALL, 0);

////@end wxInfoDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool wxInfoDialog::ShowToolTips()
{
    return TRUE;
}
