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

	//declaring methods
	void createcontrols();
	void bindeventhandler();


	void AddWhenClicked(wxCommandEvent& evt);
	void enter_action(wxCommandEvent& evt);
	void onlistkeydown(wxKeyEvent& evt);

	void AddTaskFromInput();
	void delete_selected_tasks();
};

