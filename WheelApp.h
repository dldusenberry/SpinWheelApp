#pragma once
#include <wx/wx.h>
//#include <wxcharts.h>		// Need this for a pie chart version
//#include "PieChartFrame.h"

// Code written by Demi Dusenberry


// MAINFRAME CLASS / base window
class WheelApp : public wxFrame
{
public:
	WheelApp(const wxString& title);
private:
	// Declare mainframe controlers
	void CreateControls();
	void BindEventHandlers();
	void AddSavedTasks();


	// Declare window sizers
	// Programmed them assuming I would have a pie chart widget
	// not for the current running version w/o a pie chart
	//void SetupSizers();		// NOT READY
	//void OnResize(wxSizeEvent& event);	 // NOT READY

	// Declare event handlers
	void OnAddButtonClicked(wxCommandEvent& event);
	void OnInputEnter(wxCommandEvent& event);
	void OnListKeyDown(wxKeyEvent& event);
	void OnCreateButtonClicked(wxCommandEvent& event);
	void OnClearButtonClicked(wxCommandEvent& event);
	void OnMouseEvent(wxMouseEvent& event);
	void OnWindowClosed(wxCloseEvent& event);

	// Declare widget action functions
	void AddItemFromInput();
	void DeleteSelectedItem();
	void CreateWheel();
	void MoveSelectedItem(int offset);
	void SwapItems(int i, int j);

	// Initialize all visible widgets
	wxPanel* panel;
	wxStaticText* headLineText;
	wxListBox* listBox;
	wxTextCtrl* inputField;
	wxButton* addButton;
	wxCheckListBox* checkListBox;
	wxButton* clearButton;
	wxButton* createButton;
	
	//PieChartFrame* pieChartFrame;		// FAILED

	/*
	* FAILED: Pie chart event handler
	void OnPieButtonClicked(wxCommandEvent& event);
	void OnPieSliderChanged(wxCommandEvent& event);
	void OnPieTextChanged(wxCommandEvent& event);
	void OnPieMouseEvent(wxMouseEvent& event);
	void OnPieKeyEvent(wxKeyEvent& event);
	void OnAnyButtonClicked(wxCommandEvent& event);
	*/

};


