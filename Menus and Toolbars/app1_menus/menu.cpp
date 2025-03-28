#include "menu.h"

SimpleMenu::SimpleMenu(const wxString &title)
     :wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(280,180))
{
  // Create a new wxMenuBar object to hold the menu items
menubar = new wxMenuBar;

// Create a new wxMenu object for the "File" menu
file = new wxMenu;

// Add an item to the "File" menu to quit the application
// wxID_EXIT is a predefined ID for the "Quit" action, and wxT() ensures the string is compatible with Unicode
file->Append(wxID_EXIT, wxT("&Quit"));

// Add the "File" menu to the menu bar with the label "&File"
menubar->Append(file, wxT("&File"));

// Set the menu bar for the current window
SetMenuBar(menubar);

// Connect the wxID_EXIT (Quit) menu item to the OnQuit function
// When the "Quit" menu item is selected, the OnQuit event handler will be triggered
Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SimpleMenu::OnQuit));

// Centre the window on the screen
Centre();

}

void SimpleMenu::OnQuit(wxCommandEvent &event)
{
    Close(true);
}
