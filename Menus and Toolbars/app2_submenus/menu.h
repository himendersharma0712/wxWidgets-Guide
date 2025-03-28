#include <wx/wx.h>
#include <wx/menu.h>

class SubMenu: public wxFrame // main window
{
    public:

    SubMenu(const wxString& title);

    void OnQuit(wxCommandEvent & event);

    wxMenuBar * menubar; // holds menus

    wxMenu * file; // a single drop down menu

    wxMenu * imp; // import menu item

    wxMenuItem * quit; // item within a menu 
};


