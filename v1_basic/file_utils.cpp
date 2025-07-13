#include <codecvt>
#include <locale>
#include <fstream>
#include <string>
#include <iostream>

#include "file_utils.h"
#include "task.h"


// Сохранение всех задач в файл
void saveTasks(const std::vector<Task>& tasks) {
	std::wofstream out("task.txt", std::ios::out | std::ios::trunc);
	out.imbue(std::locale(out.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>()));

	if (!out) {
		std::wcerr << L"Не удалось открыть файл для записи.\n";
		return;
	}

	for (const auto& task : tasks) {
		out << task.title << L"\n";
		out << task.description << L"\n";
		out << task.dueDate << L"\n";
		out << (task.complected ? L"1" : L"0") << L"\n";
		out << L"---\n";
	}

	out.close();
}

// Загрузка задач из файла
void loadTasks(std::vector<Task>& tasks) {
	std::wifstream in("tasks.txt");
	in.imbue(std::locale(in.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>()));

	if (!in) {
		std::wcerr << L"Файл не найден или не удалось открыть.\n";
		return;
	}

	Task task;
	std::wstring line;
	int lineCount = 0;

	while (std::getline(in, line)) {
		if (line == L"---") {
			if (lineCount == 4)
			tasks.push_back(task);
			task = Task();
			lineCount = 0;
		}
		else {
			switch (lineCount)
			{
			case 0: task.title = line;
				break;
			case 1: task.description = line;
				break;
			case 2: task.dueDate = line;
				break;
			case 3: task.complected = (line == L"1");
				break;
			}
			++lineCount;
		}
	}

	if (lineCount == 4)
		tasks.push_back(task);

	in.close();
}