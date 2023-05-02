#include "System.h"
#include <iostream>

System::System()
{
	this->annual_budget = 100000; //magic number
	this->size = 0;
	this->capacity = 10;
	this->employees = new Employee * [this->capacity];
}

System::System(const System& other)
{
	this->copy(other);
}

System::System(System&& other)
{
	this->move(std::move(other));
}

System& System::operator=(const System& other)
{
	if (this != &other) {
		this->free();
		this->copy(other);
	}

	return *this;
}

System& System::operator=(System&& other)
{
	if (this != &other) {
		this->free();
		this->move(std::move(other));
	}

	return *this;
}

System::~System()
{
	this->free();
}

bool System::add_employee(const Employee& employee)
{
	if (this->size == this->capacity) {
		this->resize();
	}

	for (size_t i = 0; i < this->size; i++) {
		if (this->employees[i] == &employee) {
			return false;
		}
	}
	this->employees[this->size] = employee.clone();
	this->size++;
	return true;
}

void System::add_project(Project project)
{
	this->projects.push_back(project);
}

void System::annual_raises()
{
	for (size_t i = 0; i < this->size; i++)
	{
		double salary_diff = this->employees[i]->get_salary();
		this->employees[i]->annual_raise();
		salary_diff -= this->employees[i]->get_salary();
		this->annual_budget += salary_diff;
	}
	std::cout << this->annual_budget << std::endl;
}

void System::copy(const System& other)
{
	this->annual_budget = other.annual_budget;
	this->projects = other.projects;
	this->capacity = other.capacity;
	this->size = other.size;

	this->employees = new Employee * [this->capacity];
	for (size_t i = 0; i < this->size; i++) {
		this->employees[i] = other.employees[i]->clone();
	}
}

void System::move(System&& other)
{
	this->annual_budget = other.annual_budget;
	this->projects = other.projects;
	this->employees = other.employees;
	this->capacity = other.capacity;
	this->size = other.size;

	other.employees = nullptr;
	other.capacity = 0;
	other.size = 0;
	other.annual_budget = 0;
	other.projects.clear();
}

void System::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete this->employees[i];
	}
	delete[] this->employees;
}

void System::resize()
{
	this->capacity *= 2;
	Employee** temp = new Employee * [this->capacity];

	for (size_t i = 0; i < this->size; i++) {
		temp[i] = this->employees[i];
	}

	delete[] this->employees;
	this->employees = temp;
}
