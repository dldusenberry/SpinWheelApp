#include "WheelApp.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Task.h"
#include <vector>
#include <string>
//#include <wxcharts.h>		// Need this for a pie chart version
//#include "PieChartFrame.h"

// Code written by Demi Dusenberry


// MAINFRAME CLASS / base window frame
WheelApp::WheelApp(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//wxPanel* panel = new wxPanel(this);
	CreateControls();
	//SetupSizers(); 	 // NOT READY
	BindEventHandlers();
	AddSavedTasks();

	// Top-level panel
	panel->Bind(wxEVT_MOTION, &WheelApp::OnMouseEvent, this);
	panel->SetBackgroundColour(wxColor(0, 0, 70));
	//Bind(wxEVT_SIZE, &WheelApp::OnResize, this);	  // NOT READY

	// Status bar widget (I only set this up for figuring out widget position placements, not really funtional for the user)
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true);


// --> END MAINFRAME <--

}




// Mainframe controls: Define widgets and  controlers
void WheelApp::CreateControls() {
	wxFont headLineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	// Initialize new panel in window frame
	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	// TOP OF SCREEN
	headLineText = new wxStaticText(panel, wxID_ANY, "Spinning Wheel of Indecision!",
		wxPoint(100, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
	headLineText->SetFont(headLineFont);	//  wxColor(250, 250, 250)
	headLineText->SetForegroundColour(wxColor(250, 250, 250)); 

	//	LEFT SIDE OF SCREEN
	// ListBox Version
	listBox = new wxListBox(panel, wxID_ANY, wxPoint(80, 110), wxSize(400, 300), wxLB_NEEDED_SB);
	listBox->SetBackgroundColour(wxColor(100, 100, 200));
	listBox->SetFont(wxFontInfo(wxSize(0, 36)).Bold());
	
	/*
	//	Pie Chart Version
	PieChartFrame* pieChart = new PieChart(panel, wxID_ANY, , wxSize(80, 300));
	pieChartFrame = new PieChartFrame("PieChart");
	pieChartFrame->HitTest(wxPoint(230, 110));
	pieChartFrame->SetCenter(wxPoint(230, 110));
	pieChartFrame->SetRadius(150);

	*/


	//	RIGHT SIDE OF SCREEN
	inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(500, 220), wxSize(295, 35), wxTE_PROCESS_ENTER);
	addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(800, 220), wxSize(100, 35));
	checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(500, 260), wxSize(300, 200));
	createButton = new wxButton(panel, wxID_ANY, "Create", wxPoint(500, 465), wxSize(100, 35));
	clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(615, 465), wxSize(100, 35));
	

}



/*
// Define window sizers   //FAILED
// Sizers allow for data interoperability when a user min/maximizes the screen
// or drags a corner of the GUI to automatically resize to fit the window
	
	//---> TO-DO:	Auto-Window Resizing <---	 // NOT READY
	// panel_top , panel_left , panel_right
	//wxPanel* panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, -1)); 
	//wxPanel* panel_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, -1)); 
	//wxPanel* panel_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, -1)); 


	wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL); // wxHORIZONTAL
	//boxSizer->Add(panel_top, 0, wxEXPAND | wxLEFT | wxRIGHT); 
	boxSizer->Add(panel_left, 0, wxEXPAND | wxALL); 
	boxSizer->Add(panel_right, 0, wxEXPAND | wxALL); 


	wxSizer* sizer_top = new wxBoxSizer(wxHORIZONTAL);
	sizer_top->Add(panel_top, 1, wxEXPAND | wxLEFT | wxRIGHT);

	//sizer_top->Add(panel_top, 1, wxEXPAND | wxALL);
	panel_top->SetSizerAndFit(sizer_top); 

	//this->SetSizerAndFit(boxSizer); 
	
	wxSizerFlags flags = wxSizerFlags().CenterHorizontal().Border(wxALL, 25);

	boxSizer->Add(headLineText, flags);
	boxSizer->Add(listBox, flags);
	boxSizer->Add(inputField, flags);
	boxSizer->Add(addButton, flags);
	boxSizer->Add(checkListBox, flags);
	boxSizer->Add(clearButton, flags);


	wxBoxSizer* inputSizer = new wxBoxSizer(wxVERTICAL);
	panel->SetSizer(boxSizer);
	boxSizer->SetSizeHints(this);
	SetClientSize(1000, 600);
	
} <---- Sizer settings should be in the mainframe above
*/


/*// Event handler:
void WheelApp::OnResize(wxSizeEvent& event)
{
	wxSize clientSize = GetClientSize();
}
// Event handler:
void WheelApp::SetupSizers()
{
}*/


// MAIN Event Handler:
// Binds all event actions to event handler functions
void WheelApp::BindEventHandlers()
{
	addButton->Bind(wxEVT_BUTTON, &WheelApp::OnAddButtonClicked, this);
	inputField->Bind(wxEVT_TEXT_ENTER, &WheelApp::OnInputEnter, this);
	checkListBox->Bind(wxEVT_KEY_DOWN, &WheelApp::OnListKeyDown, this);
	createButton->Bind(wxEVT_BUTTON, &WheelApp::OnCreateButtonClicked, this);
	clearButton->Bind(wxEVT_BUTTON, &WheelApp::OnClearButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &WheelApp::OnWindowClosed, this);

}


// Event handler:
// Click event on 'Add' button calls AddItemFromInput() action
void WheelApp::OnAddButtonClicked(wxCommandEvent& event)
{
	AddItemFromInput();
}

// Event handler:
// Keyboard event 'Enter' keystroke calls AddItemFromInpu()t action
void WheelApp::OnInputEnter(wxCommandEvent& event)
{
	AddItemFromInput();
}

// Event handler: Switch statement
// Keyboard event 'DELETE' calls DeleteSelectedItem() action
// Keyboard events 'UP', 'DOWN' keystrokes call MoveSelectedItem() action
void WheelApp::OnListKeyDown(wxKeyEvent& event)
{
	switch (event.GetKeyCode()) {
	case WXK_DELETE:
		DeleteSelectedItem();
		break;
	case WXK_UP:
		MoveSelectedItem(-1);
		break;
	case WXK_DOWN:
		MoveSelectedItem(1);
		break;
	}
}
// Event handler:
// Adds items from checkbox to list box or to make the piechart template 'clicked' the top layer panel
void WheelApp::OnCreateButtonClicked(wxCommandEvent& event)
{
	CreateWheel();
}

// Event handler:
// Click event on 'Clear' button opens a dialog window and calls Clear() action
void WheelApp::OnClearButtonClicked(wxCommandEvent& event)
{
	if (checkListBox->IsEmpty()) {
		return;
	}

	wxMessageDialog dialog(this, "Are you sure you want to clear all tasks?", "Clear", wxYES_NO | wxCANCEL);
	int result = dialog.ShowModal();

	if (result == wxID_YES) {
		checkListBox->Clear();
	}
}

// Event handler: Mostly for design/debugging purposes
// Mouse motion event displays x,y coordinates of cursor current position
void WheelApp::OnMouseEvent(wxMouseEvent& event) 
{
	wxPoint mousePos = event.GetPosition();
	wxString message = wxString::Format("Mouse (x=%d y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);

}

// Event handler:
// Close window event saves user session tasks to a file
void WheelApp::OnWindowClosed(wxCloseEvent& event)
{
	std::vector<Task> tasks;

	for (int i = 0; i < checkListBox->GetCount(); i++) {
		Task task;
		task.description = checkListBox->GetString(i);
		task.done = checkListBox->IsChecked(i);
		tasks.push_back(task);
	}

	SaveTasksToFile(tasks, "tasks.txt");
	event.Skip();
}

// Event action: 
// Adds task from input line to current tasks ListBox and clears input field
void WheelApp::AddItemFromInput()
{
	wxString description = inputField->GetValue();

	if (!description.IsEmpty()) {
		checkListBox->Insert(description, checkListBox->GetCount());
		inputField->Clear();
	}
	inputField->SetFocus();
}

// Event action:
// Loads user tasks from last session file to resume when app is reopened
void WheelApp::AddSavedTasks()
{
	std::vector<Task> tasks = LoadTasksFromFile("tasks.txt");

	for (const Task& task : tasks) {
		int index = checkListBox->GetCount();
		checkListBox->Insert(task.description, index);
		checkListBox->Check(index, task.done);
	}
}

// Event action:
// Deletes selected task from ListBox
void WheelApp::DeleteSelectedItem()
{
	int selectedIndex = checkListBox->GetSelection();

	if (selectedIndex == wxNOT_FOUND) {
		return;
	}
	checkListBox->Delete(selectedIndex);
}

void WheelApp::CreateWheel()
{
	std::vector<Task> tasks;

	for (int i = 0; i < checkListBox->GetCount(); i++) {
		Task task;
		task.description = checkListBox->GetString(i);
		task.done = checkListBox->IsChecked(i);
		tasks.push_back(task);
	}

	SaveTasksToFile(tasks, "tasks.txt");

	std::vector<Item> items = LoadItemsFromFile("tasks.txt");

	for (const Item& item : items) {
		int index = listBox->GetCount();
		listBox->Insert(item.description, index);
	}

	
}

// Event action:
// Moves selected tasks up or down in ListBox
// NOTE: for debugging only; will remove later because the goal is to have a randomized picker not a prioritized one
void WheelApp::MoveSelectedItem(int offset)
{
	int selectedIndex = checkListBox->GetSelection();

	if (selectedIndex == wxNOT_FOUND) {
		return;
	}
	int newIndex = selectedIndex + offset;

	if (newIndex >= 0 && newIndex < checkListBox->GetCount()) {
		SwapItems(selectedIndex, newIndex);
		checkListBox->SetSelection(newIndex, true);
	}
}
// Event action: Helper function to MoveSelectedItem() function above
// Swaps task index positions
void WheelApp::SwapItems(int i, int j)
{
	Task taskI{ checkListBox->GetString(i).ToStdString(), checkListBox->IsChecked(i) };
	Task taskJ{ checkListBox->GetString(j).ToStdString(), checkListBox->IsChecked(j) };

	checkListBox->SetString(i, taskJ.description);
	checkListBox->Check(i, taskJ.done);

	checkListBox->SetString(j, taskI.description);
	checkListBox->Check(j, taskI.done);
}



/*
// Pie chartevent handlers

void WheelApp::OnPieMouseEvent(wxMouseEvent& event)
{
	wxPoint mousePos = event.GetPosition();
	wxString message = wxString::Format("Mouse Event Detected (x=%d y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}
void WheelApp::OnPieTextChanged(wxCommandEvent& event)
{
}
void WheelApp::OnPieKeyEvent(wxKeyEvent& event)
{
}
void WheelApp::OnPieButtonClicked(wxCommandEvent& event) {
	wxLogStatus("Button Clicked");
	wxLogMessage("Button Clicked");
}

void WheelApp::OnPieSliderChanged(wxCommandEvent& event) {
	wxString str = wxString::Format("Slider Value: %d", event.GetInt());
	wxLogStatus(str);
}

void WheelApp::OnPieTextChanged(wxCommandEvent& event) {
	wxString str = wxString::Format("Text: %s", event.GetString());
	wxLogStatus(str);
}

*/

