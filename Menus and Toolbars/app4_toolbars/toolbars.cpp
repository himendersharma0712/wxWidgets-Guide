#include "toolbars.h"
#include <wx/bitmap.h>


Toolbar::Toolbar(const wxString &title)
    :wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(280,180))
{

    wxImage::AddHandler(new wxPNGHandler);

    wxBitmapBundle exit(wxBitmap(wxT("exit.png"), wxBITMAP_TYPE_PNG));

    wxBitmapBundle newb(wxBitmap(wxT("new.png"), wxBITMAP_TYPE_PNG));

    wxBitmapBundle open(wxBitmap(wxT("open.png"), wxBITMAP_TYPE_PNG));

    wxBitmapBundle save(wxBitmap(wxT("save.png"), wxBITMAP_TYPE_PNG));

    wxBoxSizer * vbox = new wxBoxSizer(wxVERTICAL);

    toolbar1 = new wxToolBar(this,wxID_ANY);
    toolbar1->AddTool(wxID_ANY,wxT("New file"),newb,wxT("New file"));
    toolbar1->AddTool(wxID_ANY,wxT("Save file"),save,wxT("Save file"));
    toolbar1->AddTool(wxID_ANY,wxT("Open file"),open,wxT("Open file"));
    toolbar1->Realize();


    toolbar2 = new wxToolBar(this,wxID_ANY);
    toolbar2->AddTool(wxID_EXIT, wxT("Exit application"), exit, wxT("Exit application"));
    toolbar2->Realize();

    vbox->Add(toolbar1,0,wxEXPAND);
    vbox->Add(toolbar2,0,wxEXPAND);


    SetSizer(vbox);


    Connect(wxID_EXIT,wxEVT_COMMAND_TOOL_CLICKED,
       wxCommandEventHandler(Toolbar::OnQuit));

    Centre();


}

void Toolbar::OnQuit(wxCommandEvent &event)
{
    Close(true);
}
