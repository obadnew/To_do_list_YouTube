#pragma once
#include <wx/wx.h>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	wxPanel* panel;//declaring a pointer to the class itself
	wxStaticText* headline;
	wxTextCtrl* inputfield;
	wxButton* addbutton;
	wxButton* clearbutton;
	wxCheckListBox* CheckBox;

	void createcontrols();

};

