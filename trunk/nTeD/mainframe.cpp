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
    EVT_IDLE( wxMainFrame::OnIdle )

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
    m_ChatWnd->SetSizeHints(566,368);
    m_ChatWnd->Layout();
    m_ChatWnd->Hide();
    m_DeckWnd=new wxDeckDialog(this);
    m_DeckWnd->SetSizeHints(650,368);
    m_DeckWnd->Layout();
    m_DeckWnd->Hide();
    m_InfoWnd=new wxInfoDialog(this);
    m_InfoWnd->Hide();
    m_ActiveWnd=m_LoginWnd;
    m_mainsizer=(wxFlexGridSizer*)GetSizer();
    m_mainsizer->Add(m_ActiveWnd, 1, wxALIGN_LEFT|wxEXPAND|wxALL);
    m_ActiveWnd->Show();
    Layout();
    m_TEDProtocol=new TEDProtocol();
    m_LoginWnd->m_TEDProtocol=m_TEDProtocol;
    m_ChatWnd->m_TEDProtocol=m_TEDProtocol;
    m_DeckWnd->m_TEDProtocol=m_TEDProtocol;
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

    wxBitmap item4Bitmap(_T("icons/btn_conectar.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(ConectarTool, _("Conectar"), item4Bitmap, _("Conectar"), wxITEM_NORMAL);

    item2->AddSeparator();

    wxBitmap item6Bitmap(_T("icons/btn_canales.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(ChatTool, _("Canales"), item6Bitmap, _("Canales"), wxITEM_RADIO);

    wxBitmap item7Bitmap(_T("icons/btn_baraja.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(BarajasTool, _("Barajas"), item7Bitmap, _("Barajas"), wxITEM_RADIO);

    wxBitmap item8Bitmap(_T("icons/btn_info.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(InfoTool, _("Información"), item8Bitmap, _("Información"), wxITEM_RADIO);

    wxBitmap item9Bitmap(_T("icons/btn_preferencias.png"), wxBITMAP_TYPE_PNG);
    item2->AddTool(PrefTool, _("Preferencias"), item9Bitmap, _("Preferencias"), wxITEM_RADIO);

    item2->AddSeparator();

    wxBitmap item11Bitmap(_T("icons/btn_salir.png"), wxBITMAP_TYPE_PNG);
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
    if (m_TEDProtocol->IsLogged()==FALSE)
    {
      UpdateToolbar(ConectarTool);
    }
    event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ChatTool
 */

void wxMainFrame::OnChattoolClick( wxCommandEvent& event )
{
  wxInt32 roomid;

  // Insert custom code here
  if (m_TEDProtocol->IsEditing()==TRUE)
  {
    m_TEDProtocol->DeckExit();
  }
  roomid=m_TEDProtocol->GetRecoverRoomID();
  if (roomid!=0)
  {
    m_TEDProtocol->SetRecoverRoomID(0);
    m_TEDProtocol->ChatEnter(roomid);
  }
  UpdateToolbar(ChatTool);
  event.Skip();
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for BarajasTool
 */

void wxMainFrame::OnBarajastoolClick( wxCommandEvent& event )
{
    // Insert custom code here
    if (m_TEDProtocol->IsChatting()==TRUE)
    {
      m_TEDProtocol->SetRecoverRoomID(m_TEDProtocol->GetUserChatRoomID());
      m_TEDProtocol->ChatExit();
    }
    m_DeckWnd->GoldStaticText->SetLabel(wxString::Format("%d",m_TEDProtocol->GetUserGold()));
    m_TEDProtocol->DeckEdit();
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
    case ConectarTool:
    {
      m_ActiveWnd=m_LoginWnd;
      break;
    }
    case ChatTool:
    {
      m_ActiveWnd=m_ChatWnd;
      break;
    }
    case BarajasTool:
    {
      m_ActiveWnd=m_DeckWnd;
      break;
    }
    case InfoTool:
    {
      m_ActiveWnd=m_InfoWnd;
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
/*
    MainToolBar->FindById(ChatTool)->Toggle(FALSE);
    MainToolBar->FindById(BarajasTool)->Toggle(FALSE);
    MainToolBar->FindById(InfoTool)->Toggle(FALSE);
    MainToolBar->FindById(PrefTool)->Toggle(FALSE);
*/
//    MainToolBar->FindById(SalirTool)->Toggle(FALSE);
//    MainToolBar->FindById(id)->Toggle(TRUE);
    return;
}

/*!
 * wxEVT_CLOSE_WINDOW event handler for MainFrame
 */

void wxMainFrame::OnCloseWindow( wxCloseEvent& event )
{
    // Insert custom code here
    // WE NEED TO DO SOME CLEANUP HERE
    event.Skip();
}

void wxMainFrame::OnIdle(wxIdleEvent& event)
{
  wxString msg;

  while ((msg=m_TEDProtocol->GetMessage())!=wxEmptyString)
  {
//    ::wxMessageBox(msg,_("Mensaje del Servidor"));
    ProcessMessage(msg);
  }
  event.Skip();
}

void wxMainFrame::ProcessMessage(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  if (msgtok.HasMoreTokens()==FALSE)
  {
    ::wxLogFatalError(_("Error en la respuesta del servidor."));
    return;
  }
  tok=msgtok.GetNextToken();
  // MESSAGE CODES WE CAN RECEIVE IN NEUTRAL MODE
  if (tok==_T("CE"))
  {
    ProcessChatEnter(msg);
  }
  else if (tok==_T("EE"))
  {
    ProcessDeckEdit(msg);
  }
  else if (tok==_T("GS"))
  {
    ProcessGameStart(msg);
  }
  // MESSAGE CODES WE CAN RECEIVE IN CHAT MODE
  else if (tok==_T("CX"))
  {
    ProcessChatExit(msg);
  }
  else if (tok==_T("CM"))
  {
    ProcessChatMessage(msg);
  }
  else if (tok==_T("DH"))
  {
    ProcessDuelChallenged(msg);
  }
  else if (tok==_T("DC"))
  {
    ProcessDuelCancelled(msg);
  }
  else if (tok==_T("CU"))
  {
    ProcessChatUser(msg);
  }
  // MESSAGE CODES WE CAN RECEIVE IN DECK MODE
  else if (tok==_T("EL"))
  {
    ProcessDeckList(msg);
  }
  else if (tok==_T("ED"))
  {
    ProcessDeckDescribe(msg);
  }
  // THIS COMMAND IS NOT GOING TO BE IMPLEMENTED
  // USERS MUST HAVE A FRESH COPY OF CARDS ON DISK
/*
  else if (tok==_T("EC"))
  {
    ProcessDeckCard(msg);
  }
*/
  else if (tok==_T("EN"))
  {
    ProcessDeckNew(msg);
  }
  else if (tok==_T("EM"))
  {
    ProcessDeckMove(msg);
  }
  else if (tok==_T("EK"))
  {
    ProcessDeckClear(msg);
  }
  else if (tok==_T("ER"))
  {
    ProcessDeckRename(msg);
  }
  else if (tok==_T("EA"))
  {
    ProcessDeckActive(msg);
  }
  else if (tok==_T("EG"))
  {
    ProcessDeckGet(msg);
  }
  else if (tok==_T("EX"))
  {
    ProcessDeckExit(msg);
  }
  // MESSAGE CODES WE CAN RECEIVE IN DUEL MODE
  else if (tok==_T("GZ"))
  {
    ProcessGameFinish(msg);
  }
  else if (tok==_T("GX"))
  {
    ProcessGameExit(msg);
  }
  else if (tok==_T("GI"))
  {
    ProcessGameInfo(msg);
  }
  else if (tok==_T("GF"))
  {
    ProcessGamePhase(msg);
  }
  else if (tok==_T("GC"))
  {
    ProcessGameCard(msg);
  }
  else if (tok==_T("GT"))
  {
    ProcessGameText(msg);
  }
  else if (tok==_T("GE"))
  {
    ProcessGameSelect(msg);
  }
  else if (tok==_T("GU"))
  {
    ProcessGameUse(msg);
  }
  else
  {
    ProcessUnknownMessage(msg);
  }
}

void wxMainFrame::ProcessChatEnter(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  if (tok==_T("OK"))
  {
    m_TEDProtocol->SetUserChatRoomID(m_TEDProtocol->GetTryRoomID());
    m_TEDProtocol->SetTryRoomID(0);
    m_TEDProtocol->SetChatting(TRUE);
  }
  else if (tok==_T("NO"))
  {
    tok=msgtok.GetNextToken();
    if (tok==_T("1"))
    {
      ::wxSafeShowMessage(_("Titanes"),_T("La sala está llena."));
    }
    else if (tok==_T("2"))
    {
      ::wxSafeShowMessage(_("Titanes"),_T("La sala es incorrecta."));
    }
    else
    {
      ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEC NO ")+
        tok+_T(" ")+msgtok.GetString());
    }
    m_TEDProtocol->SetTryRoomID(0);
    m_TEDProtocol->SetUserChatRoomID(0);
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.EC \n")+
      tok+msgtok.GetString());
  }
//  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessChatExit(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  if (tok==_T("OK"))
  {
    m_TEDProtocol->SetUserChatRoomID(0);
    // IF WE SET TRY ROOM TO ZERO WE CAN HAVE PROBLEMS BECAUSE
    // IF WE DO A CALL TO CHATEXIT AND THEN WE CALL CHATENTER
    // WE ARE GOING TO RECEIVE A CHATEXIT MESSAGE AFTER SETTING TRYROOM
    // SO WE ARE GOING TO UNSET IT AND THAT'S NOT GOOD
//    m_TEDProtocol->SetTryRoomID(0);
    m_TEDProtocol->SetChatting(FALSE);
    m_ChatWnd->UsuariosListCtrl->DeleteAllItems();
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nCX ")+
      tok+_T(" ")+msgtok.GetString());
    m_TEDProtocol->SetUserChatRoomID(0);
  }
//  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckEdit(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  wxInt32 deckid;
  long int longvalue;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  // EE OK <id_active_deck>
  if (tok==_T("OK"))
  {
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    deckid=longvalue;
    m_TEDProtocol->SetEditing(TRUE);
    m_TEDProtocol->SetActiveDeckID(deckid);
    m_DeckWnd->ClearDecks();
    m_TEDProtocol->DeckList();
/*
			for (int i = 0; i < 20; i++)
      {
        Decks[i] = null;
      }
			this.lblActive.Text = "Mazo: " + this.ActiveDeck;
			this.lblGold.Text =	"Oro: " + User.Gold + " €";
*/
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEE ")+
      tok+_T(" ")+msgtok.GetString());
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessGameStart(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
      // SE SUPONE QUE ESTE COMANDO LO RECIBIMOS EN MODO CHAT
			} else if (Msg[0].Equals("GS")) {
				StartDuel (Msg);
*/
}

void wxMainFrame::ProcessChatMessage(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  long int longvalue;
  wxInt32 userid;
  wxString rcvmsg;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // CM <type> <user_id> <mensaje>
  if (tok==_T("B"))
  {
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    userid=longvalue;
    rcvmsg=msgtok.GetString();
    m_ChatWnd->ProcessBroadcastChatMessage(userid,rcvmsg);
  }
  else if (tok==_T("P"))
  {
    // IT IS SUPPOSED WE SHOULD NOT GET THIS KIND OF CHAT MESSAGE
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nCM ")+
      tok+_T(" ")+msgtok.GetString());
  }
//  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDuelChallenged(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("DH")) {
				DuelReceived (Msg);
*/
}

void wxMainFrame::ProcessDuelCancelled(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("DC")) {
				DuelCancel (Msg);
*/
}

void wxMainFrame::ProcessChatUser(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  struct TEDChatter *chatter;
  long int longvalue;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // CU <tipo> <user_num> [<user_name> <deck value> <rank>]
  if (tok==_T("I"))
  {
    chatter=new struct TEDChatter;
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    chatter->Id=longvalue;
    tok=msgtok.GetNextToken();
    chatter->Name=tok;
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    chatter->DeckValue=longvalue;
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    chatter->Rank=longvalue;
    m_ChatWnd->AddUser(chatter);
  }
  else if (tok==_T("O"))
  {
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    m_ChatWnd->RemoveUser(longvalue);
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nCU ")+
      tok+_T(" ")+msgtok.GetString());
  }
//  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckList(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  long int longvalue;
  wxInt32 deckid;
  wxString deckname;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // EL <id_baraja> <nombre>
  // EL OK
  if (tok!=_T("OK"))
  {
    if (m_TEDProtocol->IsGettingDeckList()==TRUE)
    {
      // WE SHOULD CHECK IF WE ARE GETTING A CORRECT DECKID
      // BUT ON THIS MOMENT WE SUPPOSSE EVERYTHING IS FINE
      tok.ToLong(&longvalue);
      deckid=longvalue;
      deckname=msgtok.GetString();
      m_DeckWnd->ProcessDeckList(deckid,deckname);
    }
    else
    {
      ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEL ")+
        tok+_T(" ")+msgtok.GetString());
    }
  }
  else
  {
    // WE HAVE FINISHED GETTING DECK LIST
    m_TEDProtocol->SetGettingDeckList(FALSE);
    m_DeckWnd->LoadReserveDeck();
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckDescribe(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  long int longvalue;
  wxInt32 deckid;
  wxInt32 carduid;
  wxInt32 cardid;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // ED <id_baraja> <uid_carta> <id_carta>
  // ED OK
  if (tok!=_T("OK"))
  {
    tok.ToLong(&longvalue);
    deckid=longvalue;
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    carduid=longvalue;
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    cardid=longvalue;
    m_DeckWnd->ProcessDeckDescribe(deckid,carduid,cardid);
/*
    else
    {
      ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nED ")+
        tok+_T(" ")+msgtok.GetString());
    }
*/
  }
  else
  {
    // WE HAVE FINISHED GETTING CARD LIST
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckNew(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  wxInt32 deckid;
  wxString deckname;
  long int longvalue;

  deckname=m_TEDProtocol->GetNewDeck();
  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // EN OK <id_baraj> | EN NO
  if (tok==_T("OK"))
  {
    tok=msgtok.GetNextToken();
    tok.ToLong(&longvalue);
    deckid=longvalue;
    m_DeckWnd->ProcessDeckNew(deckname,deckid);
  }
  else if (tok==_T("NO"))
  {
    // WE NEED TO DO SOMETHING BETTER WITH THIS
    tok=msgtok.GetNextToken();
    ::wxSafeShowMessage(_("Titanes"),_("No puedes tener más barajas."));
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEM ")+
      tok+_T(" ")+msgtok.GetString());
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckMove(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  struct TEDMovingCard *movingcard;

  movingcard=m_TEDProtocol->GetMovingCard();
  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // EM OK | EM NO <motivo>
  if (tok==_T("OK"))
  {
    m_DeckWnd->ProcessDeckMove(movingcard);
  }
  else if (tok==_T("NO"))
  {
    // WE NEED TO DO SOMETHING BETTER WITH THIS
    tok=msgtok.GetNextToken();
    ::wxSafeShowMessage(_("Titanes"),_("La carta no cabe en la baraja destino"));
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEM ")+
      tok+_T(" ")+msgtok.GetString());
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("EM")) {
			} else {
				ListView lstFrom = (MovingDeck == 1)?lstDeckB:lstDeckA;
				ListView lstTo = (MovingDeck == 1)?lstDeckA:lstDeckB;
				clsDeck deckFrom = Decks[NumBaraja(MovingDeck == 1?cbxDeckB.Text:cbxDeckA.Text)];
				clsDeck deckTo = Decks[NumBaraja(MovingDeck == 1?cbxDeckA.Text:cbxDeckB.Text)];
				
				clsEditCard c = (clsEditCard) deckFrom.Cards[MovingId];
				c.UIDs.Remove(this.MovingUID);
				int nu = 0;
				for (int i = 0; i < lstFrom.Items.Count; i++) {
					if (lstFrom.Items[i].SubItems[6].Text.Equals ("" + MovingId)) nu = i;
				}
				if (c.UIDs.Count == 0) {
					// Era la ultima
					deckFrom.Cards.Remove(c.Id);
					lstFrom.Items.RemoveAt(nu);
				} else {
					lstFrom.Items[nu].SubItems[1].Text = "" + c.UIDs.Count;
				}
				if (deckTo.Cards[this.MovingId] == null) {
					// Añadimos (es la primera)
					clsEditCard aux = new clsEditCard();
					aux.Attack = c.Attack; aux.Cost = c.Cost;
					aux.Defense = c.Defense; aux.Freq = c.Freq;
					aux.Gold = c.Gold; aux.Id = c.Id;
					aux.Max = c.Max; aux.Name = c.Name;
					aux.Text = c.Text; aux.Type = c.Type;
					aux.UIDs = new ArrayList();
					aux.UIDs.Add (this.MovingUID);
					deckTo.Cards.Add(this.MovingId, aux);
					lstTo.Items.Add (HazFila(aux));
				} else {
					// Ya existe esa carta, añadimos el UID
					((clsEditCard)deckTo.Cards[MovingId]).UIDs.Add (MovingUID);
					for (int i = 0; i < lstTo.Items.Count; i++) {
						if (lstTo.Items[i].SubItems[6].Text.Equals ("" + MovingId)) {
							lstTo.Items[i].SubItems[1].Text = "" + ((clsEditCard)deckTo.Cards[MovingId]).UIDs.Count;
						}
					}
				}
				User.Editing = 2;
				UpdateDeckInfo ();
			}
*/
}

void wxMainFrame::ProcessDeckClear(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // EK OK | IM
  if (tok==_T("OK"))
  {
    m_DeckWnd->ProcessDeckClear();
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEK ")+
      tok+_T(" ")+msgtok.GetString());
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckRename(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // ER OK | IM
  if (tok==_T("OK"))
  {
    m_DeckWnd->ProcessDeckRename();
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nER ")+
      tok+_T(" ")+msgtok.GetString());
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckActive(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // EA OK | IM
  if (tok==_T("OK"))
  {
    m_DeckWnd->ProcessDeckActive();
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("El servidor ha respondido con un comando desconocido.\nEA ")+
      tok+_T(" ")+msgtok.GetString());
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckGet(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;
  long int longvalue;
  wxInt32 gold;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  // ED <...> | EG NO
  // EG <oro>
  if (tok!=_T("NO"))
  {
    tok.ToLong(&longvalue);
    gold=longvalue;
    m_DeckWnd->ProcessDeckGet(gold);
  }
  else
  {
    ::wxSafeShowMessage(_("Titanes"),_T("No tienes suficiente dinero para comprar otro sobre."));
  }
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
}

void wxMainFrame::ProcessDeckExit(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();
  m_TEDProtocol->SetEditing(FALSE);
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("EX")) {
				User.Editing = 0;
*/
}

void wxMainFrame::ProcessGameFinish(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GZ")) {
				GameFinish (Msg);
			}
*/
}

void wxMainFrame::ProcessGameExit(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GX")) {
				GameExit (Msg);
*/
}

void wxMainFrame::ProcessGameInfo(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GI")) {
				GameInfo (Msg);
*/
}

void wxMainFrame::ProcessGamePhase(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GF")) {
				GameFase (Msg);
*/
}

void wxMainFrame::ProcessGameCard(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GC")) {
				GameCard (Msg);
*/
}

void wxMainFrame::ProcessGameText(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			if (Msg[0].Equals("GT")) {
				String Ms = "";
				for (int i = 1; i < Msg.Length; i++) Ms += Msg[i] + " ";
				ChatWrite (this.OponentName, Ms);
*/
}

void wxMainFrame::ProcessGameSelect(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GE")) {
				GameSelect (Msg);
*/
}

void wxMainFrame::ProcessGameUse(wxString msg)
{
  wxStringTokenizer msgtok;
  wxString tok;

  msgtok=wxStringTokenizer(msg);
  tok=msgtok.GetNextToken();
  tok=msgtok.GetNextToken();

  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
/*
			} else if (Msg[0].Equals("GU")) {
				GameUse (Msg);
*/
}

void wxMainFrame::ProcessUnknownMessage(wxString msg)
{
  // WHEN WE LOSE THE CONNECTION AND WE TRY TO RECONNECT
  // WE ENTER AND INFINITE LOOP OR WAIT AT SOMEWHERE
  // SO WE NEED TO RECHECK HOW WE ARE DOING IT
  m_ChatWnd->MensajesTextCtrl->AppendText(msg+_T("\n"));
  if (m_TEDProtocol->IsConnected()==FALSE)
  {
    m_LoginWnd->ConectarButton->Enable();
    m_ChatWnd->MensajesTextCtrl->AppendText(_T("Se perdió la conexión\n"));
  }
  else
  {
    m_ChatWnd->MensajesTextCtrl->AppendText(_T("NO se perdió la conexión\n"));
    if (m_TEDProtocol->IsLogged()==FALSE)
    {
      m_LoginWnd->ConectarButton->Enable();
      m_ChatWnd->MensajesTextCtrl->AppendText(_T("Se perdió la conexión de usuario\n"));
    }
    else
    {
      m_ChatWnd->MensajesTextCtrl->AppendText(_T("NO se perdió la conexión de usuario\n"));
    }
  }
}

