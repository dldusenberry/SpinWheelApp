#include "Task.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

// Code written by Demi Dusenberry

// Function: Saves current session to a file so the user
// can reuse inputs saved from previous session
void SaveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName)
// Task is defined as a struct in the header file, but must be a vector or array
// to use with wxWidgets (see Task.h file for why i did this)
{
	std::ofstream ostream(fileName);
	ostream << tasks.size();

	for (const Task& task : tasks) {
		std::string description = task.description;
		std::replace(description.begin(), description.end(), ' ', '_');
		ostream << '\n' << description << ' ' << task.done;
	}
}

// Function: Loads previous session inputs from file to the checklist box for user
std::vector<Task> LoadTasksFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
		return std::vector<Task>();
	}
	std::vector<Task> tasks;
	std::ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++) {
		std::string description;
		bool done;

		istream >> description >> done;
		std::replace(description.begin(), description.end(), '_', ' ');
		tasks.push_back(Task{description, done});
	}
	return tasks;
}

// Function: Pushes the user inputs from the checklist box (right side of screen) to either the pie chart
// or scrollbox (box on left side of screen)
// Only supposed to push 'Checked' items but this code is incomplete
// and pushes all items currently
std::vector<Item> LoadItemsFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
		return std::vector<Item>();
	}
	std::vector<Item> items;
	std::ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++) {
		std::string description;
		bool done;

		istream >> description >> done;
		std::replace(description.begin(), description.end(), '_', ' ');
		items.push_back(Item{ description, done });
	}
	return items;
}