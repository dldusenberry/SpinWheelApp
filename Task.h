#pragma once
#include <string>
#include <vector>

// Code written by Demi Dusenberry

// Declare containers
// wxWidgets only works with a select few types of containers see here: https://docs.wxwidgets.org/3.0/group__group__class__containers.html
// I chose to make the base container a struct because my original implementation ideas were 
// to either use Yelp Fusion API or create a series of premade pie chart templates of common decisions (i.e. yes/no, A-Z, 1-10, heads/tails, etc)
// I wanted to be able to hold different types of information together with those for exception handling
struct Task
{
	std::string description;
	bool done;
};

struct Item
{
	std::string description;
	bool done;
};

// Declare task functions
void SaveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName);
std::vector<Task> LoadTasksFromFile(const std::string& fileName);
std::vector<Item> LoadItemsFromFile(const std::string& fileName);