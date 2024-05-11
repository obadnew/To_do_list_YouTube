#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	createcontrols();
}

void MainFrame::createcontrols()
{
	wxFont headlinefont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainfont(wxFontInfo(wxSize(0, 36)));

	panel = new wxPanel(this);
	panel->SetFont(mainfont);

	headline = new wxStaticText(panel, wxID_ANY, "To Do List", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTRE_HORIZONTAL);
	headline->SetFont(headlinefont);




}
