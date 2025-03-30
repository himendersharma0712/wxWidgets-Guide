#include "toolbar.h"
#include <wx/bitmap.h> // for wxBitmap

Toolbar::Toolbar(const wxString &title)
      : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    // Add PNG handler for loading PNG images
    wxImage::AddHandler(new wxPNGHandler);

    // Load the exit image as a wxBitmapBundle
    wxBitmapBundle exit(wxBitmap(wxT("exit.png"), wxBITMAP_TYPE_PNG));

    // Create the main toolbar
    wxToolBar* toolbar = CreateToolBar();

    // Add the exit button to the toolbar with the loaded image (correct signature)
    toolbar->AddTool(wxID_EXIT, wxT("Exit application"), exit, wxT("Exit application"));

    // Finalize the toolbar
    toolbar->Realize();

    // Connect the exit tool to the OnQuit function
    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED,
        wxCommandEventHandler(Toolbar::OnQuit));

    // Center the window
    Centre();
}

void Toolbar::OnQuit(wxCommandEvent &event)
{
    // Close the window when the exit button is clicked
    Close(true);
}
