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
    ReserveNumCardsStaticText = NULL;
    fgscenter = NULL;
    fgscenterchild = NULL;
    CardStaticBitmap = NULL;
    GoldStaticText = NULL;
    fgsbuttons = NULL;
    ComprarSobreButton = NULL;
    CrearBarajaButton = NULL;
    RenombrarBarajaButton = NULL;
    BorrarBarajaButton = NULL;
    ActivarBarajaButton = NULL;
    fgsright = NULL;
    DecksComboBox = NULL;
    CurrentDeckListCtrl = NULL;
    CurrentNumCardsStaticText = NULL;
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
    CurrentDeckListCtrl->SetSizeHints(262,100);
    CurrentDeckListCtrl->InsertColumn(0,_("Nombre"));
    CurrentDeckListCtrl->InsertColumn(1,_("#/M"));
    CurrentDeckListCtrl->InsertColumn(2,_("A/D"));
    CurrentDeckListCtrl->InsertColumn(3,_("Poder"));
    CurrentDeckListCtrl->SetColumnWidth(0,114);
    CurrentDeckListCtrl->SetColumnWidth(1,38);
    CurrentDeckListCtrl->SetColumnWidth(2,38);
    CurrentDeckListCtrl->SetColumnWidth(3,48);
    CardStaticBitmap->Connect(CardStaticBitmapID,-1,wxEVT_LEFT_DOWN,(wxObjectEventFunction) (wxEventFunction) (wxMouseEventFunction)&wxDeckDialog::OnLeftDown );
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

    wxFlexGridSizer* item3 = new wxFlexGridSizer(1, 3, 0, 2);
    fgschild = item3;
    item3->AddGrowableRow(0);
    item3->AddGrowableCol(0);
    item3->AddGrowableCol(2);
    item2->Add(item3, 1, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* item4 = new wxFlexGridSizer(2, 1, 2, 0);
    fgsleft = item4;
    item4->AddGrowableRow(0);
    item4->AddGrowableCol(0);
    item3->Add(item4, 1, wxGROW|wxGROW|wxALL, 0);

    wxListCtrl* item5 = new wxListCtrl( item1, ReserveListCtrlID, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
    ReserveListCtrl = item5;
    item4->Add(item5, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item6 = new wxFlexGridSizer(1, 3, 0, 2);
    item4->Add(item6, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item7 = new wxStaticText( item1, wxID_STATIC, _("Cartas:"), wxDefaultPosition, wxDefaultSize, 0 );
    item6->Add(item7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* item8 = new wxStaticText( item1, ReserveNumCardsStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    ReserveNumCardsStaticText = item8;
    item6->Add(item8, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    item6->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* item10 = new wxFlexGridSizer(2, 1, 0, 0);
    fgscenter = item10;
    item10->AddGrowableRow(0);
    item10->AddGrowableCol(0);
    item3->Add(item10, 1, wxGROW|wxGROW|wxALL, 0);

    item10->Add(5, 5, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item12 = new wxFlexGridSizer(3, 1, 5, 0);
    fgscenterchild = item12;
    item10->Add(item12, 1, wxGROW|wxGROW|wxALL, 0);

    wxBitmap item13Bitmap(wxNullBitmap);
    wxStaticBitmap* item13 = new wxStaticBitmap( item1, CardStaticBitmapID, item13Bitmap, wxDefaultPosition, wxSize(90, 120), 0 );
    CardStaticBitmap = item13;
    item12->Add(item13, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item14 = new wxFlexGridSizer(1, 3, 0, 2);
    item12->Add(item14, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item15 = new wxStaticText( item1, wxID_STATIC, _("Oro:"), wxDefaultPosition, wxDefaultSize, 0 );
    item14->Add(item15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* item16 = new wxStaticText( item1, GoldStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    GoldStaticText = item16;
    item14->Add(item16, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    item14->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* item18 = new wxFlexGridSizer(5, 1, 2, 0);
    fgsbuttons = item18;
    item12->Add(item18, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* item19 = new wxButton( item1, ComprarSobreButtonID, _("Comprar Sobre"), wxDefaultPosition, wxSize(100, -1), 0 );
    ComprarSobreButton = item19;
    item18->Add(item19, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item20 = new wxButton( item1, CrearBarajaButtonID, _("Crear Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    CrearBarajaButton = item20;
    item18->Add(item20, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item21 = new wxButton( item1, RenombrarBarajaButtonID, _("Renombrar Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    RenombrarBarajaButton = item21;
    item18->Add(item21, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item22 = new wxButton( item1, BorrarBarajaButtonID, _("Borrar Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    BorrarBarajaButton = item22;
    item18->Add(item22, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* item23 = new wxButton( item1, ActivarBarajaButtonID, _("Activar Baraja"), wxDefaultPosition, wxSize(100, -1), 0 );
    ActivarBarajaButton = item23;
    item18->Add(item23, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxFlexGridSizer* item24 = new wxFlexGridSizer(2, 1, 5, 0);
    fgsright = item24;
    item24->AddGrowableRow(1);
    item24->AddGrowableCol(0);
    item3->Add(item24, 1, wxGROW|wxGROW|wxALL, 0);

    wxString* item25Strings = NULL;
    wxComboBox* item25 = new wxComboBox( item1, DecksComboBoxID, _T(""), wxDefaultPosition, wxDefaultSize, 0, item25Strings, wxCB_READONLY|wxCB_SORT );
    DecksComboBox = item25;
    item24->Add(item25, 0, wxGROW|wxALIGN_TOP|wxALL, 0);

    wxListCtrl* item26 = new wxListCtrl( item1, CurrentDeckListCtrlID, wxDefaultPosition, wxSize(100, -1), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
    CurrentDeckListCtrl = item26;
    item24->Add(item26, 1, wxGROW|wxGROW|wxALL, 0);

    wxFlexGridSizer* item27 = new wxFlexGridSizer(1, 3, 0, 2);
    item24->Add(item27, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxStaticText* item28 = new wxStaticText( item1, wxID_STATIC, _("Cartas:"), wxDefaultPosition, wxDefaultSize, 0 );
    item27->Add(item28, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* item29 = new wxStaticText( item1, CurrentNumCardsStaticTextID, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    CurrentNumCardsStaticText = item29;
    item27->Add(item29, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    item27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end wxDeckDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool wxDeckDialog::ShowToolTips()
{
    return TRUE;
}

void wxDeckDialog::OnLeftDown(wxMouseEvent& event)
{
  // FINALLY WE HAVE BEEN ABLE TO GET MOUSE EVENT FOR WXSTATICBITMAP
  // NOW WE NEED TO DO SOMETHING USEFULL WITH IT
//  ::wxSafeShowMessage(_("Titanes"),wxString::Format("X=%d//Y=%d",event.GetX(),event.GetY()));
}

/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ReserveListCtrlID
 */

void wxDeckDialog::OnReservelistctrlidSelected( wxListEvent& event )
{
  wxBitmap clean;
  struct TEDCard *card;

  // Insert custom code here
  card=((struct TEDCard *)event.GetItem().GetData());
  if (card==NULL)
  {
    return;
  }
  LoadSmallCardBitmap(card,&clean);
  CardStaticBitmap->SetBitmap(clean);
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
//  m_TEDProtocol->DeckMove(0,m_TEDProtocol->GetCurrentDeckId(),card->Id,*card->UId[0]);
//::wxSafeShowMessage(_("Titanes"),wxString::Format("deckid %d",m_TEDProtocol->GetCurrentDeckId()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("carduid %d",card->UId[0]));
  m_TEDProtocol->DeckMove(0,m_TEDProtocol->GetCurrentDeckId(),card->Id,card->UId[0]);
  event.Skip();
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for CurrentDeckListCtrlID
 */

void wxDeckDialog::OnCurrentdecklistctrlidSelected( wxListEvent& event )
{
  wxBitmap clean;
  struct TEDCard *card;

  // Insert custom code here
  card=((struct TEDCard *)event.GetItem().GetData());
  if (card==NULL)
  {
    return;
  }
  LoadSmallCardBitmap(card,&clean);
  CardStaticBitmap->SetBitmap(clean);
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
//  m_TEDProtocol->DeckMove(m_TEDProtocol->GetCurrentDeckId(),0,card->Id,*card->UId[0]);
  m_TEDProtocol->DeckMove(m_TEDProtocol->GetCurrentDeckId(),0,card->Id,card->UId[0]);
  event.Skip();
}


/*!
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for DecksComboBoxID
 */

void wxDeckDialog::OnDeckscomboboxidSelected( wxCommandEvent& event )
{
#if 0
  wxInt32 row;
#endif
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
  return ((struct TEDCard *)item1)->Name.Cmp(((struct TEDCard *)item2)->Name);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ComprarSobreButtonID
 */

void wxDeckDialog::OnComprarsobrebuttonidClick( wxCommandEvent& event )
{
  m_TEDProtocol->DeckGet();
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
  wxInt32 numcards;
  wxInt32 *cuid;

  cuid=new wxInt32;
  *cuid=carduid;
  if (m_TEDProtocol->AlreadyHaveCardType(deckid,cardid)==FALSE)
  {
//::wxSafeShowMessage(_("Titanes"),_("POR EL FALSE"));
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
//		card->UId.Add(cuid);
		card->UId.Add(carduid);
		m_TEDProtocol->AddCard(deckid,cardid,card);
		if (deckid==0)
		{
		  row=ReserveListCtrl->InsertItem(0,card->Name);
		  ReserveListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
		  if ((card->Attack==0) && (card->Defense==0))
		  {
  		  ReserveListCtrl->SetItem(row,2,_T("--/--"));
		  }
		  else
		  {
  		  ReserveListCtrl->SetItem(row,2,wxString::Format("%d",card->Attack)+_T("/")+wxString::Format("%d",card->Defense));
		  }
		  ReserveListCtrl->SetItem(row,3,card->Cost);
		  ReserveListCtrl->SetItem(row,4,wxString::Format("%d",card->Gold));
		  ReserveListCtrl->SetItemData(row,(long int)card);
		}
		else if (deckid==m_TEDProtocol->GetCurrentDeckId())
		{
		  row=CurrentDeckListCtrl->InsertItem(0,card->Name);
		  if (card->Max==0)
		  {
  		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d/*",card->UId.GetCount()));
		  }
		  else
		  {
  		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d/%d",card->UId.GetCount(),card->Max));
		  }
		  if ((card->Attack==0) && (card->Defense==0))
		  {
  		  CurrentDeckListCtrl->SetItem(row,2,_T("--/--"));
		  }
		  else
		  {
  		  CurrentDeckListCtrl->SetItem(row,2,wxString::Format("%d",card->Attack)+_T("/")+wxString::Format("%d",card->Defense));
		  }
		  CurrentDeckListCtrl->SetItem(row,3,card->Cost);
		  CurrentDeckListCtrl->SetItemData(row,(long int)card);
		}
  }
  else
  {
//::wxSafeShowMessage(_("Titanes"),_("POR EL TRUE"));
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
		  if (card->Max==0)
		  {
  		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d/*",card->UId.GetCount()));
		  }
		  else
		  {
  		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d/%d",card->UId.GetCount(),card->Max));
		  }
    }
  }
  if (deckid==0)
  {
    numcards=m_TEDProtocol->GetDeckNumCards(deckid);
    if (numcards==-1)
    {
      return;
    }
    ReserveNumCardsStaticText->SetLabel(wxString::Format("%d",numcards));
  }
  else if (deckid==m_TEDProtocol->GetCurrentDeckId())
  {
    numcards=m_TEDProtocol->GetDeckNumCards(deckid);
    if (numcards==-1)
    {
      return;
    }
    CurrentNumCardsStaticText->SetLabel(wxString::Format("%d",numcards));
  }
}

void wxDeckDialog::ProcessDeckMove(struct TEDMovingCard *movingcard)
{
#if 0
  struct TEDDeck *srcdeck;
  struct TEDDeck *dstdeck;
#endif
  struct TEDCard *card;
  wxInt32 row;
  wxInt32 numcards;

  card=m_TEDProtocol->GetCard(movingcard->srcdeckid,movingcard->cardid);
//::wxSafeShowMessage(_("Titanes"),wxString::Format("IsEmpty %d",card->UId.IsEmpty()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("GetCount %d",card->UId.GetCount()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("FindItem %d",(int)ReserveListCtrl->FindItem(-1,(long)card)));
  m_TEDProtocol->RemoveCardUID(movingcard->srcdeckid,movingcard->cardid,movingcard->carduid);
//::wxSafeShowMessage(_("Titanes"),wxString::Format("IsEmpty %d",card->UId.IsEmpty()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("GetCount %d",card->UId.GetCount()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("FindItem %d",(int)ReserveListCtrl->FindItem(-1,(long)card)));
  ProcessDeckDescribe(movingcard->dstdeckid,movingcard->carduid,movingcard->cardid);
//::wxSafeShowMessage(_("Titanes"),wxString::Format("IsEmpty %d",card->UId.IsEmpty()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("GetCount %d",card->UId.GetCount()));
//::wxSafeShowMessage(_("Titanes"),wxString::Format("FindItem %d",(int)ReserveListCtrl->FindItem(-1,(long)card)));
  if (movingcard->srcdeckid==0)
  {
    row=ReserveListCtrl->FindItem(-1,(long)card);
//::wxSafeShowMessage(_("Titanes"),wxString::Format("fila reserva %d",row));
    if (card->UId.IsEmpty()==TRUE)
    {
//::wxSafeShowMessage(_("Titanes"),"por el deleteitem");
      ReserveListCtrl->DeleteItem(row);
    }
    else
    {
//::wxSafeShowMessage(_("Titanes"),"NO por el deleteitem");
      ReserveListCtrl->SetItem(row,1,wxString::Format("%d",card->UId.GetCount()));
    }
  }
  else
  {
    row=CurrentDeckListCtrl->FindItem(-1,(long)card);
//::wxSafeShowMessage(_("Titanes"),wxString::Format("fila baraja %d",row));
    if (card->UId.IsEmpty()==TRUE)
    {
//::wxSafeShowMessage(_("Titanes"),"por el deleteitem");
      CurrentDeckListCtrl->DeleteItem(row);
    }
    else
    {
//::wxSafeShowMessage(_("Titanes"),"NO por el deleteitem");
		  if (card->Max==0)
		  {
  		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d/*",card->UId.GetCount()));
		  }
		  else
		  {
  		  CurrentDeckListCtrl->SetItem(row,1,wxString::Format("%d/%d",card->UId.GetCount(),card->Max));
		  }
    }
  }
  if (movingcard->srcdeckid==0)
  {
    numcards=m_TEDProtocol->GetDeckNumCards(movingcard->srcdeckid);
    if (numcards==-1)
    {
      return;
    }
    ReserveNumCardsStaticText->SetLabel(wxString::Format("%d",numcards));
  }
  else if (movingcard->srcdeckid==m_TEDProtocol->GetCurrentDeckId())
  {
    numcards=m_TEDProtocol->GetDeckNumCards(movingcard->srcdeckid);
    if (numcards==-1)
    {
      return;
    }
    CurrentNumCardsStaticText->SetLabel(wxString::Format("%d",numcards));
  }
}

void wxDeckDialog::ProcessDeckNew(wxString deckname,wxInt32 deckid)
{
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
  CurrentNumCardsStaticText->SetLabel(_(""));
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

void wxDeckDialog::ProcessDeckGet(wxInt32 gold)
{
  m_TEDProtocol->SetUserGold(gold);
  GoldStaticText->SetLabel(wxString::Format("%d",gold));
}

void wxDeckDialog::LoadSmallCardBitmap(struct TEDCard *card,wxBitmap *cardbitmap,bool frombig)
{
  wxImage cardbkg;
  wxImage img;
  wxBitmap costimg;
  wxString filename;
  wxMemoryDC memdc;
  wxInt32 cardid;
  wxInt32 width;
  wxInt32 height;

  if (frombig==FALSE)
  {
    cardid=card->Id;
    cardbitmap->Create(90,120);
    memdc.SelectObject(*cardbitmap);
    cardbkg.LoadFile(_T("imgs/sframe1.gif"),wxBITMAP_TYPE_GIF);
    img.LoadFile(_T("imgs/img")+wxString::Format("%d",cardid)+_T(".gif"),wxBITMAP_TYPE_GIF);
    img.Rescale(78,53);
    memdc.DrawBitmap(wxBitmap(cardbkg),0,0);
    memdc.DrawBitmap(wxBitmap(img),6,22);
    memdc.SetTextForeground(wxColour(*wxWHITE));
    memdc.SetFont(wxFont(6,wxSWISS,wxNORMAL,wxLIGHT));
//    memdc.SetFont(wxFont(8,wxMODERN,wxNORMAL,wxLIGHT));
    memdc.GetTextExtent(card->Cost,&width,&height);
    memdc.SetClippingRegion(3,3,90-10-width,height);
    memdc.DrawText(card->Name,3,3);
    memdc.DestroyClippingRegion();
    memdc.SetClippingRegion(90-3-width,3,width,height);
    memdc.DrawText(card->Cost,90-3-width,3);
    memdc.DestroyClippingRegion();
    if ((card->Attack!=0) || (card->Defense!=0))
    {
      memdc.GetTextExtent(wxString::Format("%d / %d",card->Attack,card->Defense),&width,&height);
      memdc.SetClippingRegion(90-3-width,120-3-height,width,height);
      memdc.DrawText(wxString::Format("%d / %d",card->Attack,card->Defense),90-3-width,120-3-height);
      memdc.DestroyClippingRegion();
    }
  }
  else
  {
    LoadBigCardBitmap(card,cardbitmap);
    cardbkg=cardbitmap->ConvertToImage();
    cardbkg.Rescale(90,120);
    *cardbitmap=wxBitmap(cardbkg);
  }
}

void wxDeckDialog::LoadBigCardBitmap(struct TEDCard *card,wxBitmap *cardbitmap)
{
  wxImage cardbkg;
  wxImage img;
  wxBitmap costimg;
  wxString textline;
  wxMemoryDC memdc;
  wxInt32 cardid;
  wxInt32 width;
  wxInt32 height;

  cardid=card->Id;
  cardbitmap->Create(169,225);
  memdc.SelectObject(*cardbitmap);
  cardbkg.LoadFile(_T("imgs/bframe1.gif"),wxBITMAP_TYPE_GIF);
  img.LoadFile(_T("imgs/img")+wxString::Format("%d",cardid)+_T(".gif"),wxBITMAP_TYPE_GIF);
  memdc.DrawBitmap(wxBitmap(cardbkg),0,0);
  memdc.DrawBitmap(wxBitmap(img),11,41);
  memdc.SetTextForeground(wxColour(*wxWHITE));
  memdc.SetFont(wxFont(10,wxSWISS,wxNORMAL,wxLIGHT));
//  memdc.SetFont(wxFont(10,wxMODERN,wxNORMAL,wxLIGHT));
  memdc.GetTextExtent(card->Cost,&width,&height);
  memdc.SetClippingRegion(6,6,169-18-width,height);
  memdc.DrawText(card->Name,6,6);
  memdc.DestroyClippingRegion();
  memdc.SetClippingRegion(169-6-width,6,width,height);
  memdc.DrawText(card->Cost,169-6-width,6);
  memdc.DestroyClippingRegion();
  if ((card->Attack!=0) || (card->Defense!=0))
  {
    memdc.GetTextExtent(wxString::Format("%d / %d",card->Attack,card->Defense),&width,&height);
    memdc.SetClippingRegion(169-6-width,225-6-height,width,height);
    memdc.DrawText(wxString::Format("%d / %d",card->Attack,card->Defense),169-6-width,225-6-height);
    memdc.DestroyClippingRegion();
  }
}


/*!
 * Get bitmap resources
 */

wxBitmap wxDeckDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxDeckDialog bitmap retrieval
    return wxNullBitmap;
////@end wxDeckDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon wxDeckDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxDeckDialog icon retrieval
    return wxNullIcon;
////@end wxDeckDialog icon retrieval
}
