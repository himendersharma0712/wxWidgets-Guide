#include <wx/wx.h>


class Simple: public wxFrame // inheriting from wxFrame class
{

public:
    Simple(const wxString& title);   // constructor


private:
    wxButton* m_exitButton;
    void OnExit(wxCommandEvent& event);
};
