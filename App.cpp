#include "App.h"
#include "WheelApp.h"
#include <wx/wx.h>
//#include <wxcharts.h>  // Need this for a pie chart version
//#include "piechartframe.h"


// Code written by Demi Dusenberry


// This is where the program actually begins
// to run the GUI application
wxIMPLEMENT_APP(App); // App tells the computer to open a GUI

bool App::OnInit() {
    WheelApp* wheelApp = new WheelApp("Spin the Wheel"); // This is the base window AKA mainframe
    wheelApp->SetClientSize(1000, 600);     // Size of the GUI window on a screen
    wheelApp->Center();     // App opens to center of the screen
    wheelApp->Show(true);      
    return true;
 }


// FAILED: Pie chart app

//////wxIMPLEMENT_APP(PieChartApp);
/*
bool PieChartApp::OnInit()
{
    PieChartFrame* frame = new PieChartFrame("PieChart");
    frame->Show(true);
    return true;
}
*/




