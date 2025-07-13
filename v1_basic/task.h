#ifndef TASK_H
#define TASK_H

#include<string>

// Структура, описывающая одну задачу
struct Task {
	std::wstring title;   // Названия задачи
	std::wstring description;   // Описание задачи
	std::wstring dueDate;   // Срок выполнения
	bool complected;   // true - выполнена, false - нет
};

// Прототипы функций для работы с задачами
void addTask (std::vector<Task>& tasks);
void viewTasks (const std::vector<Task>& tasks);
void editTask (std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);

#endif