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

	inputfield = new wxTextCtrl (panel, wxID_ANY,"insert the task details", wxPoint(100, 80), wxSize(495, 35));
	addbutton = new wxButton(panel, wxID_ANY,"Add", wxPoint(600, 80), wxSize(100, 35));
	clearbutton = new wxButton (panel, wxID_ANY,"Clear", wxPoint(100, 525), wxSize(100, 35));
	CheckBox = new wxCheckListBox (panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));


}
