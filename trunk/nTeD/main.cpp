/********************
 *  Implementation
 ********************/

#include <wx/wx.h>
#include "main.h"


// program execution "starts" here
bool
MainApp::OnInit()
{
    wxMainFrame *frame;

		wxInitAllImageHandlers();
		wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load("nted.xrc");
    frame = new wxMainFrame(NULL);
    frame->SetSizeHints(400,300,1600,1200);
    frame->Show(TRUE);
    frame->Layout();
    frame->Center();
    return TRUE;
}
