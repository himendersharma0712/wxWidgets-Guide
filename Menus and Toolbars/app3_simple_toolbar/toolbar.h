#include <wx/wx.h>  // change this to wx/wx.h



class Toolbar: public wxFrame
{
   public:
        Toolbar(const wxString & title);

        void OnQuit(wxCommandEvent & event);
};