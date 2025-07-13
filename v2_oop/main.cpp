#include<iostream>
#include<fstream>
#include<string>

#include<Windows.h>
#include<locale.h>
#include"task.h"
#include"file_utils.h"

// Разработчик Жуков Евгений 

void showMenu() {
	std::cout << "\n===== Планировщик задач =====\n";
	std::cout << "1. Добавить задачу\n";
	std::cout << "2. Просомотреть задачи\n";
	std::cout << "3. Редактирвоать задачу\n";
	std::cout << "4. Удалить задачу\n";
	std::cout << "5. Изменить статус задачи\n";
	std::cout << "0. Выход\n";
	std::cout << "Выберите действие: ";
}

void displayTasks(const std::vector<Task>& tasks) {
	if (tasks.empty()) {
		std::cout << "Список задач пуст.\n";
		return;
	}
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << "\nЗадача" << i + 1 << ":\n";
		tasks[i].display();
	}
}

int main() {
	
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<Task> tasks;
	int choice;

	do {
		showMenu();
		std::cin >> choice;
		std::cin.ignore();

		switch (choice) {
		case 1: {
			std::string title, description, dueDate;

			std::cout << "Введите заголовок: ";
			std::getline(std::cin, title);

			std::cout << "Введите описанмие: ";
			std::getline(std::cin, description);

			std::cout << "Введите срок: ";
			std::getline(std::cin, dueDate);

			tasks.emplace_back(title, description, dueDate);
			std::cout << "Задача добавлена!\n";
			break;
		}

		case 2: {
			displayTasks(tasks);
			break;
		}

		case 3: {
			int index;
			displayTasks(tasks);
			std::cout << "Введите номер задачи для редактирования: ";
			std::cin >> index;
			std::cin.ignore();

			if (index < 1 || index > tasks.size()) {
				std::cout << "Неверный номер задачи!\n";
				break;
			}

			std::string newTitle, newDescription, newDate;
			std::cout << "Новый заголовок: ";
			std::getline(std::cin, newTitle);
			std::cout << "Новое описание: ";
			std::getline(std::cin, newDescription);
			std::cout << "Новая дата: ";
			std::getline(std::cin, newDate);

			tasks[index - 1].setTitle(newTitle);
			tasks[index - 1].setDescription(newDescription);
			tasks[index - 1].setDueDate(newDate);

			std::cout << "Задача обновлена!\n";
			break;
		}

		case 4: {
			int index;
			displayTasks(tasks);
			std::cout << "Введите номер задачи для удаления!\n";
			std::cin >> index;

			if (index < 1 || index > tasks.size()) {
				std::cout << "Неверный номер задачи!\n";
				break;
			}

			tasks.erase(tasks.begin() + index - 1);
			std::cout << "Задача удалена!\n";
			break;
		}

		case 5: {
			int index;
			displayTasks(tasks);
			std::cout << "Введите номер задачи для сменны статуса: ";
			std::cin >> index;

			if (index < 1 || index > tasks.size()) {
				std::cout << "Не верный номер задачи!\n";
				break;
			}

			tasks[index - 1].toggleStatus();
			std::cout << "Статус изменен!\n";
			break;
		}

		case 0:
			std::cout << "Выход...\n";
			break;

		default:
			std::cout << "Неверный выбор!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}