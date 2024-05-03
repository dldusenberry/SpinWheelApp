#pragma once
#include <wx/wx.h>
#include <wxcharts.h>

// Code written by Demi Dusenberry

// All GUI's using wxWidgets must have this to run the program
// The base class to start the GUI calling OnInit()
class App : public wxApp
{
public:
	virtual bool OnInit();
};

// FAILED: Pie chart app

/*
class PieChartApp : public wxApp
{
public:
	virtual bool OnInit();
};
*/

