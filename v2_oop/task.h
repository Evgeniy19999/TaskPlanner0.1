#ifndef TASK_H
#define TASK_H

#include<string>
#include<string>


class Task {
private:
	std::string title;   // �������� ������
	std::string description;   // �������� ������
	std::string dueDate;   // ���� ����������
	bool completed;   // true - ���������, false - ���

public:
	Task(const std::string& title, const std::string& description, const std::string& dueDate);

	//�������

	std::string getTitle() const;
	std::string getDescription() const;
	std::string getDueDate() const;
	bool isCompleted() const;

	void setTitle(const std::string& newTitle);
	void setDescription(const std::string& newDescription);
	void setDueDate(const std::string& newDueDate);

	//������ ������ � �������
	void markCompleted();
	void toggleStatus();
	void display() const;
};


#endif