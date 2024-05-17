#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	createcontrols();
	bindeventhandler();
	load_tasks();
}

void MainFrame::createcontrols()
{
	wxFont headlinefont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainfont(wxFontInfo(wxSize(0, 18)));

	panel = new wxPanel(this);
	panel->SetFont(mainfont);

	headline = new wxStaticText(panel, wxID_ANY, "To Do List", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTRE_HORIZONTAL);
	headline->SetFont(headlinefont);

	inputfield = new wxTextCtrl (panel, wxID_ANY,"insert the task details", wxPoint(100, 80), wxSize(495, 35), wxTE_PROCESS_ENTER);
	addbutton = new wxButton(panel, wxID_ANY,"Add", wxPoint(600, 80), wxSize(100, 35));
	clearbutton = new wxButton (panel, wxID_ANY,"Clear", wxPoint(100, 525), wxSize(100, 35));
	CheckBox = new wxCheckListBox (panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));


}

void MainFrame::bindeventhandler()
{
	addbutton->Bind(wxEVT_BUTTON, &MainFrame::AddWhenClicked, this);
	inputfield->Bind(wxEVT_TEXT_ENTER, &MainFrame::enter_action, this);
	CheckBox->Bind(wxEVT_KEY_DOWN, &MainFrame::onlistkeydown, this);
	clearbutton->Bind(wxEVT_BUTTON, &MainFrame::clear_button, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::when_closed, this);


}

void MainFrame::load_tasks()
{
	std::vector<Task>tasks = LoadTaskFromFile("obadtext.txt");

	for (const Task& task : tasks) {
		int index = CheckBox->GetCount();
		CheckBox->Insert(task.description, index);
		CheckBox->Check(index, task.done);
	}
}

void MainFrame::AddWhenClicked(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::enter_action(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::onlistkeydown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode()) {
	case WXK_DELETE:
		delete_selected_tasks();
		break;
	case WXK_UP:
		move_selected(-1);
		break;
	case WXK_DOWN:
		move_selected(1);
		break;
	}
}

void MainFrame::clear_button(wxCommandEvent& evt)
{
	if (CheckBox->IsEmpty()) {
		return;
	}

	wxMessageDialog warning_message(this, "are you sure you want to delete everything", "Clear", wxYES_NO | wxCANCEL);

	int result = warning_message.ShowModal();

	if (result == wxID_YES) {
		CheckBox->Clear();
	}

}

void MainFrame::when_closed(wxCloseEvent& evt)
{
	std::vector<Task> tasks;

	for (int i = 0; i < CheckBox->GetCount(); i++) {
		Task task;
		task.description = CheckBox->GetString(i);
		task.done = CheckBox->IsChecked(i);
		tasks.push_back(task);
	}
	SaveTaskToFile(tasks, "obadtext.txt");
	evt.Skip();
}

void MainFrame::AddTaskFromInput()
{
	wxString description = inputfield->GetValue();
	if (!description.IsEmpty()) {
		CheckBox->Insert(description, CheckBox->GetCount());
		inputfield->Clear();
	}
	inputfield->SetFocus();
}

void MainFrame::delete_selected_tasks()
{
	int selected_index = CheckBox->GetSelection();

	if (selected_index == wxNOT_FOUND) {
		return;
	}
	CheckBox->Delete(selected_index);
}

void MainFrame::move_selected(int offset)
{
	int selected_index = CheckBox->GetSelection();
	if (selected_index == wxNOT_FOUND) {
		return;
	}

	int new_index = selected_index + offset;

	if (new_index >= 0 && new_index < CheckBox->GetCount()) {
		swap_task(selected_index, new_index);
		CheckBox->SetSelection(new_index, true);
	}
}

void MainFrame::swap_task(int i, int j)
{
	Task Taski{ CheckBox->GetString(i).ToStdString(), CheckBox->IsChecked(i) };
	Task Taskj{ CheckBox->GetString(j).ToStdString(), CheckBox->IsChecked(j) };

	CheckBox->SetString(i, Taskj.description);
	CheckBox->Check(i, Taskj.done);

	CheckBox->SetString(j, Taski.description);
	CheckBox->Check(j, Taski.done);

}
