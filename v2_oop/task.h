#ifndef TASK_H
#define TASK_H

#include<string>
#include<string>


class Task {
private:
	std::string title;   // Названия задачи
	std::string description;   // Описание задачи
	std::string dueDate;   // Срок выполнения
	bool completed;   // true - выполнена, false - нет

public:
	Task(const std::string& title, const std::string& description, const std::string& dueDate);

	//Геттеры

	std::string getTitle() const;
	std::string getDescription() const;
	std::string getDueDate() const;
	bool isCompleted() const;

	void setTitle(const std::string& newTitle);
	void setDescription(const std::string& newDescription);
	void setDueDate(const std::string& newDueDate);

	//Методы работы с задачей
	void markCompleted();
	void toggleStatus();
	void display() const;
};


#endif