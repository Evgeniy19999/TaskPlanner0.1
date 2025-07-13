#include<iostream>
#include<string>

#include"file_utils.h"
#include"task.h"


Task::Task(const std::string& title, const std::string& description, const std::string& dueDate)
	:title(title), description(description), dueDate(dueDate), completed(false){}

std::string Task::getTitle() const {
	return title;
}

std::string Task::getDescription() const {
	return description;
}

std::string Task::getDueDate() const {
	return dueDate;
}

bool Task::isCompleted() const {
	return completed;
}

void Task::setTitle(const std::string& newTitle) {
	title = newTitle;
}

void Task::setDescription(const std::string& newDescription) {
	description = newDescription;
}

void Task::setDueDate(const std::string& newDate) {
	dueDate = newDate;
}

void Task::markCompleted() {
	completed = true;
}

void Task::toggleStatus() {
	completed = !completed;
}

void Task::display() const {
	std::cout << "Заголовок: " << title << std::endl;
	std::cout << "Описание: " << description << std::endl;
	std::cout << "Срок: " << dueDate << std::endl;
	std::cout << "Статус: " << (completed ? "Выполнено" : "Не выполнено") << std::endl;
}