#ifndef PANELS_H
#define PANELS_H



#include <wx/wx.h>
#include <wx/panel.h>

class LeftPanel : public wxPanel
{
    public:
    LeftPanel (wxPanel * parent); // constr

    void onPlus(wxCommandEvent & event);

    void onMinus(wxCommandEvent & event);

    // two buttons + and -
    wxButton * m_plus; // ptr to a button 
    wxButton * m_minus;

    wxPanel * m_parent; // ptr to a panel

    int count;
};




class RightPanel : public wxPanel
{
    public:
    RightPanel(wxPanel * parent); // constructor

    void OnSetText(wxCommandEvent & event);

    wxStaticText * m_text;
};


const int ID_PLUS = 101;
const int ID_MINUS = 102;


#endif