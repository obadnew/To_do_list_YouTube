#pragma once
#include <vector>
#include <string>

struct Task
{
	std::string description;
	bool done;
};

void SaveTaskToFile(const std::vector<Task>& tasks, const std::string& filename);
std::vector<Task> LoadTaskFromFile(const std::string& filename);
