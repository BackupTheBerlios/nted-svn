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
    EVT_LIST_ITEM_SELECTED( ReserveListCtrlID, wxDeckDialog::OnReservelistctrlidSelected )
    EVT_LIST_ITEM_ACTIVATED( ReserveListCtrlID, wxDeckDialog::OnReservelistctrlidItemActivated )

    EVT_COMBOBOX( DecksComboBoxID, wxDeckDialog::OnDeckscomboboxidSelected )

    EVT_LIST_ITEM_SELECTED( CurrentDeckListCtrlID, wxDeckDialog::OnCurrentdecklistctrlidSelected )
    EVT_LIST_ITEM_ACTIVATED( CurrentDeckListCtrlID, wxDeckDialog::OnCurrentdecklistctrlidItemActivated )

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
    ComprarSobreButton = NULL;
    CrearBarajaButton = NULL;
    RenombrarBarajaButton = NULL;
    BorrarBarajaButton = NULL;
    ActivarBarajaButton = NULL;
    fgsright = NULL;
    DecksComboBox = NULL;
    CurrentDeckListCtrl = NULL;
////@end wxDeckDialog member initialisation

////@begin wxDeckDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end wxDeckDialog creation
    ReserveListCtrl->SortItems(wxListCompareFunction2,0);
    ReserveListCtrl->SetSizeHints(290,100);
    ReserveListCtrl->InsertColumn(0,_("Nombre"));
    ReserveListCtrl->InsertColumn(1,_("#"));
    ReserveListCtrl->InsertColumn(2,_("A/D"));
    ReserveListCtrl->InsertColumn(3,_("Poder"));
    ReserveListCtrl->InsertColumn(4,_("Valor"));
    ReserveListCtrl->SetColumnWidth(0,126);
    ReserveListCtrl->SetColumnWidth(1,24);
    ReserveListCtrl->SetColumnWidth(2,40);
    ReserveListCtrl->SetColumnWidth(3,50);
    ReserveListCtrl->SetColumnWidth(4,46);
    CurrentDeckListCtrl->SortItems(wxListCompareFunction2,0);
    CurrentDeckListCtrl->SetSizeHints(260,100);
    CurrentDeckListCtrl->InsertColumn(0,_("Nombre"));
    CurrentDeckListCtrl->InsertColumn(1,_("#/M"));
    CurrentDeckListCtrl->InsertColumn(2,_("A/D"));
    CurrentDeckListCtrl->InsertColumn(3,_("Poder"));
    CurrentDeckListCtrl->SetColumnWidth(0,126);
    CurrentDeckListCtrl->SetColumnWidth(1,40);
    CurrentDeckListCtrl->SetColumnWidth(2,40);
    CurrentDeckListCtrl->SetColumnWidth(3,50);
    fgsleft->Layout();
    fgsright->Layout();
    Layout();

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

    wxListCtrl* item5 = new wxListCtrl( item1, ReserveListCtrlID, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
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

    wxFlexGridSizer* item10 = new wxFlexGridSizer(5, 1, 2, 0);
    fgsbuttons = item10;
    item8->Add(item10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* item11 = new wxButton( item1, ComprarSobreButtonID, _("Comprar Sobre"), wxDefaultPosition, wxSize(100, -1), 0 );
    ComprarSobreButton = item11;
    item10->Add(item11, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item12 = new wxButton( item1, CrearBarajaButtonID, _("Crear Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    CrearBarajaButton = item12;
    item10->Add(item12, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item13 = new wxButton( item1, RenombrarBarajaButtonID, _("Renombrar Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    RenombrarBarajaButton = item13;
    item10->Add(item13, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item14 = new wxButton( item1, BorrarBarajaButtonID, _("Borrar Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    BorrarBarajaButton = item14;
    item10->Add(item14, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item15 = new wxButton( item1, ActivarBarajaButtonID, _("Activar Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    ActivarBarajaButton = item15;
    item10->Add(item15, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item16 = new wxFlexGridSizer(2, 1, 5, 0);
    fgsright = item16;
    item16->AddGrowableRow(1);
    item16->AddGrowableCol(0);
    item3->Add(item16, 1, wxGROW|wxGROW|wxALL, 0);

    wxString item17Strings[] = {
        _("Pejelagarto barquero")
    };
    wxComboBox* item17 = new wxComboBox( item1, DecksComboBoxID, _T(""), wxDefaultPosition, wxDefaultSize, 1, item17Strings, wxCB_READONLY|wxCB_SORT );
    DecksComboBox = item17;
    item16->Add(item17, 0, wxGROW|wxALIGN_TOP|wxALL, 0);

    wxListCtrl* item18 = new wxListCtrl( item1, CurrentDeckListCtrlID, wxDefaultPosition, wxSize(100, -1), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
    CurrentDeckListCtrl = item18;
    item16->Add(item18, 1, wxGROW|wxGROW|wxALL, 0);

////@end wxDeckDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool wxDeckDialog::ShowToolTips()
{
    return TRUE;
}
/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ReserveListCtrlID
 */

void wxDeckDialog::OnReservelistctrlidSelected( wxListEvent& event )
{
    // Insert custom code here
    event.Skip();
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for ReserveListCtrlID
 */

void wxDeckDialog::OnReservelistctrlidItemActivated( wxListEvent& event )
{
    // Insert custom code here
    event.Skip();
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for CurrentDeckListCtrlID
 */

void wxDeckDialog::OnCurrentdecklistctrlidSelected( wxListEvent& event )
{
    // Insert custom code here
    event.Skip();
}

/*!
 * wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for CurrentDeckListCtrlID
 */

void wxDeckDialog::OnCurrentdecklistctrlidItemActivated( wxListEvent& event )
{
    // Insert custom code here
    event.Skip();
}


/*!
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for DecksComboBoxID
 */

void wxDeckDialog::OnDeckscomboboxidSelected( wxCommandEvent& event )
{
    // Insert custom code here
    event.Skip();
}

void wxDeckDialog::ClearDecks()
{
  ReserveListCtrl->DeleteAllItems();
  DecksComboBox->Clear();
  CurrentDeckListCtrl->DeleteAllItems();
}

void wxDeckDialog::ProcessDeckList(wxInt32 deckid,wxString deckname)
{
  wxInt32 *value;

  value=new wxInt32;
  *value=deckid;
  ::wxSafeShowMessage(_("Titanes"),deckname);
  DecksComboBox->Append(deckname);
//  DecksComboBox->Append(deckname,value);
//  DecksComboBox->Refresh();
  m_TEDProtocol->AddDeck(deckid,deckname);
}

void wxDeckDialog::LoadReserveDeck()
{
  m_TEDProtocol->DeckDescribe(0);
}

void wxDeckDialog::ProcessDeckDescribe(wxInt32 deckid,wxInt32 carduid,wxInt32 cardid)
{
/*
				if (Decks[deck].Cards[id] == null) {
					// La creamos
					clsEditCard c = new clsEditCard();
					StreamReader Data = ((StreamReader)new StreamReader("cards\\card" + id + ".txt"));
					String[] CD = new String[10]; 
					for (int i = 0; i < 10; i++) CD[i] = Data.ReadLine();
					Data.Close();
					// 6 = 6 2 2 6 60 8 P U Rey_de_Copas Arrolla. 
					//    id type attack defense gold max cost freq nombre descr.
					c.Attack = Convert.ToInt32(CD[2]);
					c.Cost = CD[6];
					c.Defense = Convert.ToInt32(CD[3]);
					c.Freq = CD[7];
					c.Gold = Convert.ToInt32(CD[4]);
					c.Id = id;
					c.Max = Convert.ToInt32(CD[5]);
					c.Name = CD[8];
					c.Text = CD[9];
					c.Type = Convert.ToInt32(CD[1]);
					c.UIDs = new ArrayList();
					c.UIDs.Add (uid);
					Decks[deck].Cards.Add (id,c);
				} else {
					// La añadimos
					((clsEditCard)Decks[deck].Cards[id]).UIDs.Add(uid);
				}
*/
}

int wxCALLBACK wxListCompareFunction2(long item1,long item2,long sortData)
{
  return 0;//((struct TEDChatter *)item1)->Name.Cmp(((struct TEDChatter *)item2)->Name);
}


