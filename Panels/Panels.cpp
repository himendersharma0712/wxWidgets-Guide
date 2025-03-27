#include "Panels.h"
#include "Communicate.h"
#include <wx/stattext.h>

LeftPanel::LeftPanel(wxPanel *parent): 
wxPanel(parent,-1,wxPoint(-1,-1),wxSize(-1,-1),wxBORDER_SUNKEN)
{
    count = 0;


    m_parent = parent;

    // initializing two buttons 

    m_plus = new wxButton(this,ID_PLUS,wxT("+"),wxPoint(10,10));

    m_minus = new wxButton(this,ID_MINUS,wxT("-"),wxPoint(10,60));

    // connecting the buttons to an action

    Connect(ID_PLUS,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(LeftPanel::onPlus));

    Connect(ID_MINUS,wxEVT_COMMAND_BUTTON_CLICKED,wxCommandEventHandler(LeftPanel::onMinus));


}

void LeftPanel::onPlus(wxCommandEvent &event)
{
    count++;

    // setting up communciation to the text label
    Communicate * comm = (Communicate * ) m_parent -> GetParent();

    // using comm to set the text label
    comm->m_rp->m_text->SetLabel(wxString::Format(wxT("%d"),count));


}

void LeftPanel::onMinus(wxCommandEvent &event)
{
    count--;

    // setting up communciation to the text label
    Communicate * comm = (Communicate * ) m_parent -> GetParent();

    // using comm to set the text label
    comm->m_rp->m_text->SetLabel(wxString::Format(wxT("%d"),count));

}

RightPanel::RightPanel(wxPanel *parent)
: wxPanel(parent,wxID_ANY,wxDefaultPosition,wxSize(270,150),wxBORDER_SUNKEN)
{

    m_text = new wxStaticText(this,-1,wxT("0"),wxPoint(40,60));

}


