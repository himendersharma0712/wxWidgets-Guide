#include "simple.h"
#include "main.h"


IMPLEMENT_APP(MyApp)    // this macro actually runs the app


bool MyApp::OnInit(){   // this is just the function definition


Simple * simple = new Simple(wxT("MEIN APP"));
simple->Show(true);

return true;


}
