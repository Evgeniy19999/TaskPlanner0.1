
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include<vector>
#include<fstream>
#include"task.h"

void saveTasks(const std::vector<Task>& tasks);
void loadTasks(std::vector<Task>& task);

#endif