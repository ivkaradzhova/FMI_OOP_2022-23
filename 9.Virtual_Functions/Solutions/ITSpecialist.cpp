#include "ITSpecialist.h"

ITSpecialist::ITSpecialist(std::string name, const unsigned int experience, const double salary) : Employee(name, experience, salary)
{
	this->capacity = 10;
	this->size = 0;
	this->projects = new Project * [capacity];
}

ITSpecialist::ITSpecialist(const ITSpecialist& other) : Employee(other)
{
	this->copy(other);
}

ITSpecialist::ITSpecialist(ITSpecialist&& other) : Employee(std::move(other))
{
	this->move(std::move(other));
}

ITSpecialist& ITSpecialist::operator=(const ITSpecialist& other)
{
	if (this != &other) {
		Employee::operator=(other);
		delete[] this->projects;
		this->copy(other);
	}
	return *this;
}

ITSpecialist& ITSpecialist::operator=(ITSpecialist&& other)
{
	if (this != &other) {
		Employee::operator=(other);
		delete[] this->projects;
		this->move(std::move(other));
	}
	return *this;
}

ITSpecialist::~ITSpecialist()
{
	delete[] this->projects;
}

double ITSpecialist::get_avg_difficulty() const
{
	double sum = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		sum = this->projects[i]->get_difficulty();
	}
	return sum / this->size;
}

unsigned int ITSpecialist::get_project_count() const
{
	return this->size;
}

bool ITSpecialist::add_project(Project& project)
{
	if (this->size == this->capacity) {
		this->resize();
	}

	for (size_t i = 0; i < this->size; i++) {
		if (this->projects[i] == &project) {
			return false;
		}
	}
	this->projects[this->size] = &project;
	this->size++;
	return true;
}

void ITSpecialist::copy(const ITSpecialist& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	this->projects = new Project * [this->capacity];
	for (size_t i = 0; i < this->size; i++) {
		this->projects[i] = other.projects[i];
	}
}

void ITSpecialist::move(ITSpecialist&& other)
{
	this->projects = other.projects;
	this->capacity = other.capacity;
	this->size = other.size;
	
	other.projects = nullptr;
	other.capacity = 0;
	other.size = 0;
}

void ITSpecialist::resize()
{
	this->capacity *= 2;
	Project** temp = new Project * [this->capacity];

	for (size_t i = 0; i < this->size; i++) {
		temp[i] = this->projects[i];
	}

	delete[] this->projects;
	this->projects = temp;
}
