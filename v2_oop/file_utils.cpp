#include <fstream>
#include <string>
#include <iostream>

#include "file_utils.h"
#include "task.h"


// Сохранение всех задач в файл
void saveTasks(const std::vector<Task>& tasks) {
	std::ofstream out("tasks.txt", std::ios::out | std::ios::trunc);

	
	if (!out) {
		std::cerr << "Не удалось открыть файл для записи!" << std::endl;
		return;
	}

	for (const auto& task : tasks) {
		out << task.getTitle() << "\n";
		out << task.getDescription() << "\n";
		out << task.getDueDate() << "\n";
		out << task.isCompleted() << "\n";
		out << "---\n";
	}

	out.close();
}

// Загрузка задач из файла
void loadTasks(std::vector<Task>& tasks) {
	std::ifstream in("tasks.txt");

	if (!in) {
		std::cerr << "Файл не найден или не удалось открыть." << std::endl;
		return;
	}

	std::string title, description, dueDate;
	bool completed;

	while (std::getline(in, title) &&
		std::getline(in, description) &&
		std::getline(in, dueDate) &&
		in >> completed) {
			in.ignore();
			Task task(title, description, dueDate);
			if (completed) task.markCompleted();
			tasks.push_back(task);
		}
		
	in.close();
}