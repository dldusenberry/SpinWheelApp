﻿# SpinWheelApp

STATUS: *Work in Progess*

This is my university final project in C++.
This is an unfinished GUI Windows desktop application that helps the user make a descision at random. 
The program allows a user to input a list of items (a to-do list, dinner options, board game choices, etc.) Inspired by: [Websites like this](https://wheelofdecision.com/)




So far it looks like this...

![ScreenshotSpinWheelApp1](https://github.com/dldusenberry/SpinWheelApp/assets/98852855/5eb5ffea-0357-4b2e-b6fc-18687727dbc9)


# The Goal
As of right now I have a scrolling listbox on the left side of the window that will look more like a slot machine and scroll on a timer and then slow down to make a random winning selection.

I plan to work on a wxPieChart widget to replace the scrolling listbox with an adjustable pie chart, that will also spin on a timer and slow to make a random selection. When I say adjustable, I mean to make the size of each slice of the pie adjust to fit evenly for varying number of slices/user inputs.



# GUI Library Sources
### wxWidgets
I used wxWidgets open source GUI library to build the GU Interface. 

*See INSTALL.md for downloading this library*

[Link to wxWidgets website and documentation](https://www.wxwidgets.org/)

[Link to wxWidgets Github repository](https://github.com/wxWidgets/wxWidgets)


### wxCharts
I also used wxCharts open source library, which is still in the development stage.

This is a third party library for creating charts in a wxWidgets application.

*See INSTALL.md for downloading this library*

[Link to wxWidgets website](https://www.wxishiko.com/wxCharts) (no documentation yet)

[Link to xwCharts Github repository](https://github.com/wxIshiko/wxCharts/tree/main)

All files modified and used are credited in the work.



# Future Work

I am making an attempt to build on this unfinished wxPieChart widget for my application rather than making an animated pie chart image for the spinning wheel.

*See wxCharts branch to see where I'm at on this wxPieChart widget project*

If I figure it out I will try to contribute to the wxCharts repository!

All files modified and used are credited to: Copyright (c) 2015-2021 Xavier Leclercq and the wxCharts contributors
