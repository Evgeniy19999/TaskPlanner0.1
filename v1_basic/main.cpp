#include<windows.h>
#include<iostream>
#include<clocale>
#include<vector>
#include<fcntl.h>
#include<io.h>

#include"task.h"
#include"file_utils.h"

// Разработчик Жуков Евгений 

using namespace std;


int main() {
	SetConsoleOutputCP(65001);   // Включаем поддержку UTF - 8 для консоли
	SetConsoleCP(65001);
	setlocale(LC_ALL, "rus");

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	vector<Task> tasks;
	loadTasks(tasks);
	int choice;

	// Меню пользователя
	do {
		wcout << L"\n===== Планировщик задач =====" << endl;
		wcout << L"1. Добавить задачу" << endl;
		wcout << L"2. Просомотреть задачи" << endl;
		wcout << L"3. Редактирвоать задачу" << endl;
		wcout << L"4. Удалить задачу" << endl;
		wcout << L"5. Выход" << endl;
		wcout << L"Выберите действие: ";
		wcin >> choice;
		wcin.ignore();

		switch (choice) {
		case 1:
			addTask(tasks);
			saveTasks(tasks);
			break;
		case 2:
			viewTasks(tasks);
			break;
		case 3:
			editTask(tasks);
			saveTasks(tasks);
			break;
		case 4:
			deleteTask(tasks);
			saveTasks(tasks);
			break;
		case 5:
			wcout << L"Выход из программы..." << endl;
			break;
		default:
			wcout << L"Неверный выбор. Повоторите попытку." << endl;
		}
	} while (choice != 5);

	return 0;
}