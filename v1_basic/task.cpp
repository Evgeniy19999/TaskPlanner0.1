#include<iostream>
#include<vector>

#include"file_utils.h"
#include"task.h"


using namespace std;

// Добавление новой задачи
void addTask(vector<Task>& tasks) {
	Task newTask;

	wcout << L"Введите заголовок задачи: ";
	getline(wcin, newTask.title);
	wcout << L"Введите описание задачи: ";
	getline(wcin, newTask.description);
	wcout << L"Введите срок выполнения: ";
	getline(wcin, newTask.dueDate);

	wcout << L"Выберите статус: \n";
	wcout << L"1. Выполнена\n";
	wcout << L"0. Не выполнена\n";
	wcout << L"Ваш выбор: ";

	int statusChoice;
	wcin >> statusChoice;
	wcin.ignore();

	newTask.complected = (statusChoice == 1);
	wcin.ignore();


	tasks.push_back(newTask);
	wcout << L"Задача успешно добавлена!" << endl;

	saveTasks(tasks);
}

// Просмотр всех задач
void viewTasks(const vector<Task>& tasks) {
	if (tasks.empty()) {
		wcout << L"Список задач пуст." << endl;
		return;
	}

	for (size_t i = 0; i < tasks.size(); ++i) {
		wcout << L"\nЗадача#" << i + 1 << endl;
		wcout << L"Заголовок: " << tasks[i].title << endl;
		wcout << L"Описание: " << tasks[i].description << endl;
		wcout << L"Срок: " << tasks[i].dueDate << endl;
		wcout << L"Статус: " << (tasks[i].complected ? L"Выполнена" : L"Не выполнена") << endl;
		
	}
}

// Редактирование задачи
void editTask(vector<Task>& tasks) {
	if (tasks.empty()) {
		wcout << L"Нет задач для редактировнаия." << endl;
		return;
	}

	int index;
	wcout << L"Введите номер задачи для редактирования: ";
	wcin >> index;
	wcin.ignore();

	if (index < 1 || index > tasks.size()) {
		wcout << L"Неверный номер задачи." << endl;
		return;
	}

	Task& task = tasks[index - 1];

	wcout << L"Редактирование задачи #" << index << endl;

	wcout << L"Введите новый заголовок (или Enter, чтобы оставить): ";
	wstring input;
	getline(wcin, input);
	if (!input.empty()) task.title = input;

	wcout << L"Введите новое описание (или Enter, чтобы оставить): ";
	getline(wcin, input);
	if (!input.empty()) task.description = input;

	wcout << L"Введите новую дату (или Enter, чтобы остваить): ";
	getline(wcin, input);
	if (!input.empty()) task.dueDate = input;

	wcout << L"Изменить статус:\n";
	wcout << L"1. Выполнена\n";
	wcout << L"0. Не выполнена\n";
	wcout << L"Или нажмите Enter, чтобы оставить текущий статус: ";
	getline(wcin, input);
	if (!input.empty()) {
		if (input == L"1")
			task.complected = true;
		else if (input == L"0")
			task.complected = false;
		else
			wcout << L"Неверный ввод, статус не изменён.\n";
	}

	wcout << L"Задача обновлена!" << endl;

	saveTasks(tasks);
}

// Удаление задачи
void deleteTask(vector<Task>& tasks) {
	if (tasks.empty()) {
		wcout << L"Нет задач для удаления." << endl;
		return;
	}

	int index;
	wcout << L"Введите номер задачи для удаления: ";
	wcin >> index;
	wcin.ignore();

	if (index < 1 || index >> tasks.size()) {
		wcout << L"Неверный номер задачи." << endl;
		return;
	}

	tasks.erase(tasks.begin() + (index - 1));
	wcout << L"Задача удалена." << endl;

	saveTasks(tasks);
}