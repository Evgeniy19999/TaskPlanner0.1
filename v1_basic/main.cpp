#include<windows.h>
#include<iostream>
#include<clocale>
#include<vector>
#include<fcntl.h>
#include<io.h>

#include"task.h"
#include"file_utils.h"

// ����������� ����� ������� 

using namespace std;


int main() {
	SetConsoleOutputCP(65001);   // �������� ��������� UTF - 8 ��� �������
	SetConsoleCP(65001);
	setlocale(LC_ALL, "rus");

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	vector<Task> tasks;
	loadTasks(tasks);
	int choice;

	// ���� ������������
	do {
		wcout << L"\n===== ����������� ����� =====" << endl;
		wcout << L"1. �������� ������" << endl;
		wcout << L"2. ������������ ������" << endl;
		wcout << L"3. ������������� ������" << endl;
		wcout << L"4. ������� ������" << endl;
		wcout << L"5. �����" << endl;
		wcout << L"�������� ��������: ";
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
			wcout << L"����� �� ���������..." << endl;
			break;
		default:
			wcout << L"�������� �����. ���������� �������." << endl;
		}
	} while (choice != 5);

	return 0;
}