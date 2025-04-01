#include "main.h"
#include "absolute.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Absolute * absolute = new Absolute(wxT("Absolute Positioning"));
    absolute->Show(true);

    return true;
}