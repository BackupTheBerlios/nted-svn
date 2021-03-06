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
  EVT_LIST_ITEM_SELECTED(CanalesListCtrlID, wxChatDialog::OnChatRoomSelected)
  EVT_TEXT_ENTER( MensajeTextCtrlID, wxChatDialog::OnMensajetextctrlidEnter )
  EVT_LIST_ITEM_SELECTED( UsuariosListCtrlID, wxChatDialog::OnUsuarioslistctrlidSelected )
  EVT_LIST_ITEM_ACTIVATED( UsuariosListCtrlID, wxChatDialog::OnUsuarioslistctrlidItemActivated )
  EVT_LIST_ITEM_RIGHT_CLICK( UsuariosListCtrlID, wxChatDialog::OnUsuarioslistctrlidRightClick )

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
    UsuariosListCtrl->SortItems(wxListCompareFunction,0);
    UsuariosListCtrl->SetSizeHints(200,100);
    UsuariosListCtrl->InsertColumn(0,_("Nombre"));
    UsuariosListCtrl->InsertColumn(1,_("Valor"));
    UsuariosListCtrl->InsertColumn(2,_("Ranking"));
/*
    UsuariosListCtrl->InsertItem(0,_T("0,0"));
    UsuariosListCtrl->SetItem(0,1,_T("0,1"));
    UsuariosListCtrl->SetItem(0,2,_T("0,2"));
    UsuariosListCtrl->InsertItem(1,_T("1,0"));
    UsuariosListCtrl->SetItem(1,1,_T("1,1"));
    UsuariosListCtrl->SetItem(1,2,_T("1,2"));
    UsuariosListCtrl->InsertItem(2,_T("2,0"));
    UsuariosListCtrl->SetItem(2,1,_T("2,1"));
    UsuariosListCtrl->SetItem(2,2,_T("2,2"));
*/
    UsuariosListCtrl->SetColumnWidth(0,100);
    UsuariosListCtrl->SetColumnWidth(1,40);
    UsuariosListCtrl->SetColumnWidth(2,55);
/*
    UsuariosListCtrl->InsertItem(3,_T("Nombre largo"));
    UsuariosListCtrl->SetItem(3,1,_T("3,1"));
    UsuariosListCtrl->SetItem(3,2,_T("3,2"));
*/
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
    item5->Create( item1, MensajesTextCtrlID, _T(""), wxDefaultPosition, wxSize(340, 300), wxTE_MULTILINE|wxTE_RICH2 );
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
    item10->Create( item1, UsuariosListCtrlID, wxDefaultPosition, wxSize(200, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
    UsuariosListCtrl = item10;
    item9->Add(item10, 1, wxALIGN_RIGHT|wxALL, 0);

    item9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxListCtrl* item12 = new wxListCtrl;
    item12->Create( item1, CanalesListCtrlID, wxDefaultPosition, wxSize(200, 100), wxLC_REPORT|wxLC_NO_HEADER|wxLC_SINGLE_SEL );
    CanalesListCtrl = item12;
    item9->Add(item12, 0, wxALIGN_RIGHT|wxALL, 0);

////@end wxChatDialog content construction

// REMEMBER WE NEED TO SET USER IN ASCENDING ORDER
//    item10->Create( item1, UsuariosListCtrlID, wxDefaultPosition, wxSize(200, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING );
}

/*!
 * Should we show tooltips?
 */

bool wxChatDialog::ShowToolTips()
{
    return TRUE;
}

/*!
 * wxEVT_COMMAND_TEXT_ENTER event handler for MensajeTextCtrlID
 */

void wxChatDialog::OnMensajetextctrlidEnter( wxCommandEvent& event )
{
    // Insert custom code here
    OnEnviarbuttonClick(event);
    event.Skip();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for EnviarButton
 */

void wxChatDialog::OnEnviarbuttonClick( wxCommandEvent& event )
{
    // Insert custom code here
  m_TEDProtocol->SendMessage(MensajeTextCtrl->GetValue()+_T("\n"));
  event.Skip();
}

void wxChatDialog::SetChannelNames()
{
  wxInt32 chatroomid;
  wxInt32 numchatrooms;
  struct TEDChatRoom *chatroom;
  wxString chatroomname;

//  ::wxSafeShowMessage(_("Titanes"),_("Antes del ClearAll"));
  CanalesListCtrl->ClearAll();
//  ::wxSafeShowMessage(_("Titanes"),_("Antes del GetNumChatRooms"));
  numchatrooms=m_TEDProtocol->GetNumChatRooms();
//  ::wxSafeShowMessage(_("Titanes"),_("Antes del for"));
  CanalesListCtrl->InsertColumn(0,_("Sala"));
  for (chatroomid=0;chatroomid<numchatrooms;chatroomid++)
  {
//    chatroomname=m_TEDProtocol->GetChatRoomName(chatroom);
    chatroom=m_TEDProtocol->GetChatRoom(chatroomid);
    CanalesListCtrl->InsertItem(chatroomid,chatroom->RoomName);
    CanalesListCtrl->SetItemData(chatroomid,(long int)chatroom);
  }
  CanalesListCtrl->SetColumnWidth(0,wxLIST_AUTOSIZE);
//  ::wxSafeShowMessage(_("Titanes"),_("Despues del for"));
  return;
}

void wxChatDialog::AddUser(struct TEDChatter *chatter)
{
  wxInt32 row;
  
  row=UsuariosListCtrl->InsertItem(0,chatter->Name);
  UsuariosListCtrl->SetItem(row,1,wxString::Format("%d",chatter->DeckValue));
  UsuariosListCtrl->SetItem(row,2,wxString::Format("%d",chatter->Rank));
  UsuariosListCtrl->SetItemData(row,(long int)chatter);
  m_TEDProtocol->AddUser(chatter);
}

void wxChatDialog::RemoveUser(wxInt32 userid)
{
  wxInt32 row;
  struct TEDChatter *chatter;

  chatter=m_TEDProtocol->GetUser(userid);
  if (chatter==NULL)
  {
    return;
  }
  m_TEDProtocol->RemoveUser(userid);
  row=UsuariosListCtrl->FindItem(-1,(long int)chatter);
  UsuariosListCtrl->DeleteItem(row);
}

void wxChatDialog::ProcessBroadcastChatMessage(wxInt32 userid,wxString rcvmsg)
{
  struct TEDChatter *chatter;
  wxString username;

  if (userid==0)
  {
    username=_("servidor");
  }
  else
  {
    chatter=m_TEDProtocol->GetUser(userid);
    if (chatter==NULL)
    {
      username=_("desconocido");
    }
    else
    {
      username=chatter->Name;
    }
  }
  MensajesTextCtrl->AppendText(username+_T(": ")+rcvmsg+_T("\n"));
}

int wxCALLBACK wxListCompareFunction(long item1,long item2,long sortData)
{
  return ((struct TEDChatter *)item1)->Name.Cmp(((struct TEDChatter *)item2)->Name);
}

void wxChatDialog::OnChatRoomSelected( wxListEvent& event )
{
  if (m_TEDProtocol->IsChatting()==FALSE)
  {
    m_TEDProtocol->SetTryRoomID(((struct TEDChatRoom *)event.GetItem().GetData())->RoomId);
    m_TEDProtocol->ChatEnter(m_TEDProtocol->GetTryRoomID());
  }
  // WE NEED TO ADD SUPPORT FOR CHANGING THE OUR CURRENT CHANNEL
  // WITHOUT SENDING THE COMMAND BY HAND
  else
  {
    m_TEDProtocol->ChatExit();
    m_TEDProtocol->SetTryRoomID(((struct TEDChatRoom *)event.GetItem().GetData())->RoomId);
    m_TEDProtocol->ChatEnter(m_TEDProtocol->GetTryRoomID());
  }
//  ::wxSafeShowMessage(_("Titanes"),event.GetItem().GetText());
//  ::wxSafeShowMessage(_("Titanes XXX"),((struct TEDChatRoom *)event.GetItem().GetData())->RoomName);
  event.Skip();
}

void wxChatDialog::ProcessDuelChallenged(wxInt32 userid)
{
#if 0
  wxInt32 row;
#endif
  struct TEDChatter *chatter;
#if 0
  wxInt32 accepted;
#endif
  wxFont original;
  wxFont challenge;

  chatter=m_TEDProtocol->GetUser(userid);
  if (chatter==NULL)
  {
    return;
  }
#if 0
  row=UsuariosListCtrl->FindItem(-1,(long int)chatter);
  // MAYBE WE SHOULD DO SOMETHING IF THE CHALLENGER HAS ALREADY EXITED
#endif
  // MAYBE WE SHOULD NOT DISPLAY A MESSAGEBOX ASKING TO ACCEPT OR DECLINE
  // MAYBE A BETTER SOLUTION IS JUST TO WRITE IT AS A CHAT MESSAGE AND
  // IF THE PLAYER SELECT THE CHALLENGER FROM THE LIST THEN WE CONSIDER
  // THE USER HAS ACCEPTED THE CHALLENGE BUT THEN WE NEED A WAY TO BE ABLE
  // TO CANCEL IT ACTIVELY (NOT WAITING UNTIL IT GETS CANCELLED BY TIMEOUT)
  original=MensajesTextCtrl->GetFont();
  challenge=original;
  challenge.SetStyle(wxITALIC);
  challenge.SetWeight(wxBOLD);
  MensajesTextCtrl->SetDefaultStyle(wxTextAttr(wxNullColour, wxNullColour,challenge));
  MensajesTextCtrl->AppendText(chatter->Name+wxString::Format(" le ha desafiado [baraja: %d, rango: %d]\n",chatter->DeckValue,chatter->Rank));
  MensajesTextCtrl->SetDefaultStyle(wxTextAttr(wxNullColour, wxNullColour,original));
#if 0
  accepted=::wxMessageBox(chatter->Name+_(" le ha desafiado [baraja: ")+chatter->DeckValue+_(", rango: ")+chatter->Rank+_("]\n"),_("Titanes"),wxYES_NO,this);
  if (accepted==wxYES)
  {
  }
  else
  {
  }
#endif
/*
			} else if (Msg[0].Equals("DH")) {
			Chatter c = ((Chatter)User.Chatters[Msg[1]]);
			String Tx = c.Name + " le desafia [baraja: " + c.DeckValue + ", rango:" + c.Rank + "]\n";
			rtbChat.AppendText (Tx);
			rtbChat.Select (rtbChat.Text.Length - Tx.Length, Tx.Length);
			rtbChat.SelectionFont = new Font("Verdana",8,FontStyle.Bold);
			rtbChat.SelectionColor = Color.Gray;
			
			int li = -1;
			for (int i = 0; i < lstChatters.Items.Count; i++) {
				if (lstChatters.Items[i].SubItems[0].Text.Equals(c.Name)) li = i;
			}
			if (li >= 0) lstChatters.Items[li].ImageIndex = 1;
*/
}

/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for UsuariosListCtrlID
 */

void wxChatDialog::OnUsuarioslistctrlidSelected( wxListEvent& event )
{
/*
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
*/
  event.Skip();
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for UsuariosListCtrlID
 */

void wxChatDialog::OnUsuarioslistctrlidItemActivated( wxListEvent& event )
{
/*
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
*/
  event.Skip();
}

/*!
 * wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK event handler for UsuariosListCtrlID
 */

void wxChatDialog::OnUsuarioslistctrlidRightClick( wxListEvent& event )
{
    // Insert custom code here
    event.Skip();
}


