#ifndef TASK_H
#define TASK_H

#include<string>

// ���������, ����������� ���� ������
struct Task {
	std::wstring title;   // �������� ������
	std::wstring description;   // �������� ������
	std::wstring dueDate;   // ���� ����������
	bool complected;   // true - ���������, false - ���
};

// ��������� ������� ��� ������ � ��������
void addTask (std::vector<Task>& tasks);
void viewTasks (const std::vector<Task>& tasks);
void editTask (std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);

#endif