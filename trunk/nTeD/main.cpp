/********************
 *  Implementation
 ********************/

#include <wx/wx.h>
#include "main.h"


// program execution "starts" here
bool
MainApp::OnInit()
{
		wxInitAllImageHandlers();
		wxFileSystem::AddHandler(new wxInternetFSHandler);
		wxSocketBase::Initialize();
//		wxXmlResource::Get()->InitAllHandlers();
//    wxXmlResource::Get()->Load("nted.xrc");
    frame = new wxMainFrame(NULL);
    frame->Show(TRUE);
    frame->SetSizeHints(684,433,1600,1200);
    frame->Layout();
    frame->Fit();
    frame->Center();
    return TRUE;
}
