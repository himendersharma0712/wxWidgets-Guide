#include "main.h"
#include "menu.h"


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    SubMenu * smenu = new SubMenu(wxT("SubMenuApp"));
    smenu->Show(true);

    return true;
}