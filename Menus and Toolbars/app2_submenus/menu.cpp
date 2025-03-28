#include "menu.h"

SubMenu::SubMenu(const wxString &title)
  :wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(280,180))
{

    menubar = new wxMenuBar;

    file = new wxMenu;

    // adding menu items to file menu
    file->Append(wxID_ANY,wxT("&New"));
    file->Append(wxID_ANY,wxT("&Open"));
    file->Append(wxID_ANY,wxT("&Save"));
    file->Append(wxID_ANY,wxT("&Nothing"));
    file->AppendSeparator(); // add a horizontal separator 

    // another Menu 
    imp = new wxMenu;
    imp->Append(wxID_ANY, wxT("Import cpp files"));
    imp->Append(wxID_ANY, wxT("Import kotlin files"));
    imp->Append(wxID_ANY, wxT("Import python files"));


    // appending second menu to the first one
    file->AppendSubMenu(imp,wxT("&Import"));

    // appending a menuitem manually 
    quit = new wxMenuItem(file,wxID_EXIT,wxT("&QUIT\tCtrl+W"));
    file->Append(quit);


    // appending file menu to menubar
    menubar->Append(file,wxT("&File"));



    // lets add a few useless menus

    wxMenu * help = new wxMenu;
    wxMenu * view = new wxMenu;
    wxMenu * find = new wxMenu;
    wxMenu * settings = new wxMenu;

    //  adding useless menuitems to useless menus
    help->Append(wxID_ANY,wxT("&can't help you!"));
    view->Append(wxID_ANY,wxT("&no views for you"));
    find->Append(wxID_ANY,wxT("&Nothing to find..."));
    settings->Append(wxID_ANY,wxT("&About Device"));

    // appending empty menus to menubar
    menubar->Append(help,wxT("&Help"));
    menubar->Append(view,wxT("&View"));
    menubar->Append(find,wxT("&Find"));
    menubar->Append(settings,wxT("&Settings"));



    // finally setting the menubar
    SetMenuBar(menubar);


    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(SubMenu::OnQuit));
    
    Centre();

}

void SubMenu::OnQuit(wxCommandEvent &event)
{
     Close(true);
}