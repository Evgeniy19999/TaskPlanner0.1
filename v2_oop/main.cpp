#include<iostream>
#include<fstream>
#include<string>

#include<Windows.h>
#include<locale.h>
#include"task.h"
#include"file_utils.h"

// ����������� ����� ������� 

void showMenu() {
	std::cout << "\n===== ����������� ����� =====\n";
	std::cout << "1. �������� ������\n";
	std::cout << "2. ������������ ������\n";
	std::cout << "3. ������������� ������\n";
	std::cout << "4. ������� ������\n";
	std::cout << "5. �������� ������ ������\n";
	std::cout << "0. �����\n";
	std::cout << "�������� ��������: ";
}

void displayTasks(const std::vector<Task>& tasks) {
	if (tasks.empty()) {
		std::cout << "������ ����� ����.\n";
		return;
	}
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << "\n������" << i + 1 << ":\n";
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

			std::cout << "������� ���������: ";
			std::getline(std::cin, title);

			std::cout << "������� ���������: ";
			std::getline(std::cin, description);

			std::cout << "������� ����: ";
			std::getline(std::cin, dueDate);

			tasks.emplace_back(title, description, dueDate);
			std::cout << "������ ���������!\n";
			break;
		}

		case 2: {
			displayTasks(tasks);
			break;
		}

		case 3: {
			int index;
			displayTasks(tasks);
			std::cout << "������� ����� ������ ��� ��������������: ";
			std::cin >> index;
			std::cin.ignore();

			if (index < 1 || index > tasks.size()) {
				std::cout << "�������� ����� ������!\n";
				break;
			}

			std::string newTitle, newDescription, newDate;
			std::cout << "����� ���������: ";
			std::getline(std::cin, newTitle);
			std::cout << "����� ��������: ";
			std::getline(std::cin, newDescription);
			std::cout << "����� ����: ";
			std::getline(std::cin, newDate);

			tasks[index - 1].setTitle(newTitle);
			tasks[index - 1].setDescription(newDescription);
			tasks[index - 1].setDueDate(newDate);

			std::cout << "������ ���������!\n";
			break;
		}

		case 4: {
			int index;
			displayTasks(tasks);
			std::cout << "������� ����� ������ ��� ��������!\n";
			std::cin >> index;

			if (index < 1 || index > tasks.size()) {
				std::cout << "�������� ����� ������!\n";
				break;
			}

			tasks.erase(tasks.begin() + index - 1);
			std::cout << "������ �������!\n";
			break;
		}

		case 5: {
			int index;
			displayTasks(tasks);
			std::cout << "������� ����� ������ ��� ������ �������: ";
			std::cin >> index;

			if (index < 1 || index > tasks.size()) {
				std::cout << "�� ������ ����� ������!\n";
				break;
			}

			tasks[index - 1].toggleStatus();
			std::cout << "������ �������!\n";
			break;
		}

		case 0:
			std::cout << "�����...\n";
			break;

		default:
			std::cout << "�������� �����!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}