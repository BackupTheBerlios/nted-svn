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

    EVT_BUTTON( ComprarSobreButtonID, wxDeckDialog::OnComprarsobrebuttonidClick )

    EVT_BUTTON( CrearBarajaButtonID, wxDeckDialog::OnCrearbarajabuttonidClick )

    EVT_BUTTON( RenombrarBarajaButtonID, wxDeckDialog::OnRenombrarbarajabuttonidClick )

    EVT_BUTTON( BorrarBarajaButtonID, wxDeckDialog::OnBorrarbarajabuttonidClick )

    EVT_BUTTON( ActivarBarajaButtonID, wxDeckDialog::OnActivarbarajabuttonidClick )

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
    ReserveListCtrl->SetColumnWidth(0,114);
    ReserveListCtrl->SetColumnWidth(1,24);
    ReserveListCtrl->SetColumnWidth(2,40);
    ReserveListCtrl->SetColumnWidth(3,50);
    ReserveListCtrl->SetColumnWidth(4,41);
    CurrentDeckListCtrl->SortItems(wxListCompareFunction2,0);
    CurrentDeckListCtrl->SetSizeHints(260,100);
    CurrentDeckListCtrl->InsertColumn(0,_("Nombre"));
    CurrentDeckListCtrl->InsertColumn(1,_("#/M"));
    CurrentDeckListCtrl->InsertColumn(2,_("A/D"));
    CurrentDeckListCtrl->InsertColumn(3,_("Poder"));
    CurrentDeckListCtrl->SetColumnWidth(0,114);
    CurrentDeckListCtrl->SetColumnWidth(1,38);
    CurrentDeckListCtrl->SetColumnWidth(2,38);
    CurrentDeckListCtrl->SetColumnWidth(3,48);
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

    wxString* item17Strings = NULL;
    wxComboBox* item17 = new wxComboBox( item1, DecksComboBoxID, _T(""), wxDefaultPosition, wxDefaultSize, 0, item17Strings, wxCB_READONLY|wxCB_SORT );
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
  struct TEDCard *card;

  // Insert custom code here
  if (m_TEDProtocol->GetCurrentDeckId()<=0)
  {
    return;
  }
  card=((struct TEDCard *)event.GetItem().GetData());
  if (card==NULL)
  {
    return;
  }
  m_TEDProtocol->DeckMove(0,m_TEDProtocol->GetCurrentDeckId(),card->Id,card->UId[0]);
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
  struct TEDCard *card;

  // Insert custom code here
  if (m_TEDProtocol->GetCurrentDeckId()<=0)
  {
    return;
  }
  card=((struct TEDCard *)event.GetItem().GetData());
  if (card==NULL)
  {
    return;
  }
  m_TEDProtocol->DeckMove(m_TEDProtocol->GetCurrentDeckId(),0,card->Id,card->UId[0]);
  event.Skip();
}


/*!
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for DecksComboBoxID
 */

void wxDeckDialog::OnDeckscomboboxidSelected( wxCommandEvent& event )
{
  wxInt32 row;
  wxInt32 *deckid;

  // Insert custom code here
  CurrentDeckListCtrl->DeleteAllItems();
  deckid=(wxInt32 *)DecksComboBox->GetClientData(DecksComboBox->GetSelection());
  if (deckid!=NULL)
  {
    m_TEDProtocol->ClearDeck(*deckid);
    m_TEDProtocol->SetCurrentDeckId(*deckid);
    m_TEDProtocol->DeckDescribe(*deckid);
  }
  else
  {
    m_TEDProtocol->SetCurrentDeckId(-1);
  }
  event.Skip();
}

int wxCALLBACK wxListCompareFunction2(long item1,long item2,long sortData)
{
  return 0;//((struct TEDChatter *)item1)->Name.Cmp(((struct TEDChatter *)item2)->Name);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ComprarSobreButtonID
 */

void wxDeckDialog::OnComprarsobrebuttonidClick( wxCommandEvent& event )
{
  event.Skip();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for CrearBarajaButtonID
 */

void wxDeckDialog::OnCrearbarajabuttonidClick( wxCommandEvent& event )
{
  wxString deckname;

  // Insert custom code here
  deckname=::wxGetTextFromUser(_("Nombre de la baraja: "),_("Titanes"),wxEmptyString,this);
  if (deckname!=wxEmptyString)
  {
    // WE COULD TRY TO CHECK IF USER HAS ENTERED A STUPID NAME LIKE SPACES,
    // TABS OR ANY GROUP OF BLANK CHARACTER BUT TAKING INTO ACCOUNT THAT
    // THE SERVER WILL RETURN AN ILLEGAL MESSAGE AND CLOSE THE CONNECTION
    // THE USER WILL NOT DO SUCH A STUPID THING AGAIN
    m_TEDProtocol->DeckNew(deckname);
  }
  event.Skip();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for RenombrarBarajaButtonID
 */

void wxDeckDialog::OnRenombrarbarajabuttonidClick( wxCommandEvent& event )
{
  wxInt32 *deckid;
  wxString deckname;

  // Insert custom code here
  deckid=(wxInt32 *)DecksComboBox->GetClientData(DecksComboBox->GetSelection());
  if (deckid==NULL)
  {
    return;
  }
  deckname=::wxGetTextFromUser(_("Nuevo nombre de la baraja: "),_("Titanes"),wxEmptyString,this);
  if (deckname!=wxEmptyString)
  {
    // WE COULD TRY TO CHECK IF USER HAS ENTERED A STUPID NAME LIKE SPACES,
    // TABS OR ANY GROUP OF BLANK CHARACTER BUT TAKING INTO ACCOUNT THAT
    // THE SERVER WILL RETURN AN ILLEGAL MESSAGE AND CLOSE THE CONNECTION
    // THE USER WILL NOT DO SUCH A STUPID THING AGAIN
    m_TEDProtocol->DeckRename(*deckid,deckname);
  }
  event.Skip();
}

void wxDeckDialog::OnBorrarbarajabuttonidClick( wxCommandEvent& event )
{
  wxInt32 *deckid;

  // Insert custom code here
  deckid=(wxInt32 *)DecksComboBox->GetClientData(DecksComboBox->GetSelection());
  if (deckid==NULL)
  {
    return;
  }
  else if (*deckid==m_TEDProtocol->GetActiveDeckID())
  {
    return;
  }
  m_TEDProtocol->DeckClear(*deckid);
  event.Skip();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ActivarBarajaButtonID
 */

void wxDeckDialog::OnActivarbarajabuttonidClick( wxCommandEvent& event )
{
  // Insert custom code here
  wxInt32 *deckid;

  // Insert custom code here
  deckid=(wxInt32 *)DecksComboBox->GetClientData(DecksComboBox->GetSelection());
  if (deckid==NULL)
  {
    return;
  }
  else if (*deckid==m_TEDProtocol->GetActiveDeckID())
  {
    return;
  }
  m_TEDProtocol->DeckActive(*deckid);
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

  // WE ARE NOT GOING TO LIST RESERVE DECK AS A USABLE DECK
  value=new wxInt32;
  *value=deckid;
  if (deckid!=0)
  {
    DecksComboBox->Append(deckname,value);
  }
  m_TEDProtocol->AddDeck(deckid,deckname);
}

void wxDeckDialog::LoadReserveDeck()
{
  m_TEDProtocol->DeckDescribe(0);
}

void wxDeckDialog::ProcessDeckDescribe(wxInt32 deckid,wxInt32 carduid,wxInt32 cardid)
{
  struct TEDCard *card;
  wxFileInputStream *input;
  wxTextInputStream *text;
  wxString filename;
  long int longvalue;
  wxInt32 row;

  if (m_TEDProtocol->AlreadyHaveCardType(deckid,cardid)==FALSE)
  {
    card=new struct TEDCard;
    filename=_T("cards/card")+wxString::Format("%d",cardid)+_T(".txt");
    input=new wxFileInputStream(filename);
    if (input->Ok()==FALSE)
    {
      ::wxSafeShowMessage(_("Titanes"),_("Error abriendo el fichero ")+filename);
      input->~wxFileInputStream();
      free(input);
      free(card);
      return;
    }
    text=new wxTextInputStream(*input);
		// 6 = 6  2    2      6       60   8   P    U    Rey_de_Copas Arrolla. 
		//     id type attack defense gold max cost freq nombre       descr.
		text->ReadLine().ToLong(&longvalue);
		card->Id=longvalue;
    if (card->Id!=cardid)
    {
      ::wxSafeShowMessage(_("Titanes"),_("El identificador de la carta no es correcto."));
    }
		text->ReadLine().ToLong(&longvalue);
		card->Type=longvalue;
		text->ReadLine().ToLong(&longvalue);
		card->Attack=longvalue;
		text->ReadLine().ToLong(&longvalue);
		card->Defense=longvalue;
		text->ReadLine().ToLong(&longvalue);
		card->Gold=longvalue;
		text->ReadLine().ToLong(&longvalue);
		card->Max=longvalue;
		card->Cost=text->ReadLine();
		card->Freq=text->ReadLine();
		card->Name=text->ReadLine();
		card->Text=text->ReadLine();
		card->UId.Clear();
		card->UId.Add(carduid);
		m_TEDProtocol->AddCard(deckid,cardid,card);
		if (deckid==0)
		{
		  row=ReserveListCtrl->InsertItem(0,card->Name);
		  ReserveListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
		  ReserveListCtrl->SetItem(row,2,wxString::Format("%d",card->Attack)+_T("/")+wxString::Format("%d",card->Defense));
		  ReserveListCtrl->SetItem(row,3,card->Cost);
		  ReserveListCtrl->SetItem(row,4,wxString::Format("%d",card->Gold));
		  ReserveListCtrl->SetItemData(row,(long int)card);
		}
		else if (deckid==m_TEDProtocol->GetCurrentDeckId())
		{
		  row=CurrentDeckListCtrl->InsertItem(0,card->Name);
		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
		  CurrentDeckListCtrl->SetItem(row,2,wxString::Format("%d",card->Attack)+_T("/")+wxString::Format("%d",card->Defense));
		  CurrentDeckListCtrl->SetItem(row,3,card->Cost);
		  CurrentDeckListCtrl->SetItemData(row,(long int)card);
		}
  }
  else
  {
    m_TEDProtocol->AddCardUID(deckid,cardid,carduid);
    card=m_TEDProtocol->GetCard(deckid,cardid);
    if (deckid==0)
    {
      row=ReserveListCtrl->FindItem(-1,(long int)card);
      ReserveListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
    }
    else
    {
      row=CurrentDeckListCtrl->FindItem(-1,(long int)card);
      CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
    }
  }
}

void wxDeckDialog::ProcessDeckMove(struct TEDMovingCard *movingcard)
{
  struct TEDDeck *srcdeck;
  struct TEDDeck *dstdeck;
  struct TEDCard *card;
  wxInt32 row;

  card=m_TEDProtocol->GetCard(movingcard->srcdeckid,movingcard->cardid);
  m_TEDProtocol->RemoveCardUID(movingcard->srcdeckid,movingcard->cardid,movingcard->carduid);
  ProcessDeckDescribe(movingcard->dstdeckid,movingcard->carduid,movingcard->cardid);
  if (movingcard->srcdeckid==0)
  {
    row=ReserveListCtrl->FindItem(-1,(long int)card);
    if (card->UId.IsEmpty()==TRUE)
    {
      ReserveListCtrl->DeleteItem(row);
    }
    else
    {
      ReserveListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
    }
  }
  else
  {
    row=CurrentDeckListCtrl->FindItem(-1,(long int)card);
    if (card->UId.IsEmpty()==TRUE)
    {
      CurrentDeckListCtrl->DeleteItem(row);
    }
    else
    {
      CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
    }
  }
}

void wxDeckDialog::ProcessDeckNew(wxString deckname,wxInt32 deckid)
{
/*
  wxString cadena=deckname;

  cadena=deckname;
::wxSafeShowMessage(_("Titanes 1"),_("stepA"));
::wxSafeShowMessage(_("Titanes 2"),cadena+wxString::Format(" %d",deckid));
*/
  ProcessDeckList(deckid,deckname);
}

void wxDeckDialog::ProcessDeckClear()
{
  wxInt32 row;
  wxInt32 *deckid;

  // Insert custom code here
  ReserveListCtrl->DeleteAllItems();
  CurrentDeckListCtrl->DeleteAllItems();
  row=DecksComboBox->GetSelection();
  deckid=(wxInt32 *)DecksComboBox->GetClientData(row);
  DecksComboBox->Delete(row);
  if (deckid!=NULL)
  {
    m_TEDProtocol->ClearDeck(*deckid);
  }
  m_TEDProtocol->SetCurrentDeckId(-1);
  m_TEDProtocol->ClearDeck(0);
  LoadReserveDeck();
}

void wxDeckDialog::ProcessDeckRename()
{
  wxInt32 row;
  wxInt32 *deckid;
  struct TEDRenamingDeck *renamingdeck;

  // Insert custom code here
  renamingdeck=m_TEDProtocol->GetRenamingDeck();
  if (renamingdeck==NULL)
  {
    return;
  }
  row=DecksComboBox->GetSelection();
  deckid=(wxInt32 *)DecksComboBox->GetClientData(row);
  DecksComboBox->SetString(row,renamingdeck->deckname);
  DecksComboBox->SetSelection(row);
}

void wxDeckDialog::ProcessDeckActive()
{
  wxInt32 deckid;

  // Insert custom code here
  deckid=m_TEDProtocol->GetActivatingDeck();
  if (deckid==-1)
  {
    return;
  }
  m_TEDProtocol->SetActiveDeckID(deckid);
}

