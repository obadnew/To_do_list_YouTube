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
	void load_tasks();

	void AddWhenClicked(wxCommandEvent& evt);
	void enter_action(wxCommandEvent& evt);
	void onlistkeydown(wxKeyEvent& evt);
	void clear_button(wxCommandEvent& evt);
	void when_closed(wxCloseEvent& evt);

	void AddTaskFromInput();
	void delete_selected_tasks();
	void move_selected(int offset);
	void swap_task(int i, int j);
};

