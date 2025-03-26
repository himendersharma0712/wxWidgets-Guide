
#include "simple.h"


Simple::Simple(const wxString& title) : wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(1280,720))
{

    // setting up a panel to contain the button
    wxPanel* panel = new wxPanel(this,wxID_ANY);

    m_exitButton = new wxButton(panel, wxID_EXIT, wxT("Exit"), wxPoint(640,200), wxSize(200, 80)); // creating a button in our panel

    m_exitButton->SetBackgroundColour(wxColor(80,200,120));

    // Binding the button click event to our event handler
    Bind(wxEVT_BUTTON, &Simple::OnExit,this); // event type, functor object(basically passing a function), this

    SetIcon(wxIcon(wxT("icon_.png"))); // to set an icon for the app

    Centre(); // centre the window
}


void Simple::OnExit(wxCommandEvent& event){

    Close(true);
}
