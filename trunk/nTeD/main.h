#ifndef _MAIN_H_
#define _MAIN_H_

#include <wx/wx.h>
#include <wx/image.h>
#include "wx/xrc/xmlres.h"          // XRC XML resouces
#include "mainframe.h"

class MainApp : public wxApp
{
  public:
    bool OnInit(void);
//    wxCriticalSection m_critsec;
    wxMainFrame *frame;

};

DECLARE_APP(MainApp)

/*****************************************************************
 * Create a new application object: this macro will allow
 * wxWindows to create the application object during program
 * execution (it's better than using a static object for many
 * reasons) and also declares the accessor function wxGetApp()
 * which will return the reference of the right type (i.e. MyApp
 * and not wxApp)
 *
 *****************************************************************/

IMPLEMENT_APP(MainApp)


#endif // _MAIN_H_
