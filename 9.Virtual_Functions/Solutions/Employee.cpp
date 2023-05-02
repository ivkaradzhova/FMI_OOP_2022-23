#include "Employee.h"

Employee::Employee(std::string name, const unsigned int experience, const double salary)
	: name(name), experience(experience), salary(salary)
{
}

double Employee::get_salary() const
{
	return this->salary;
}

void Employee::annual_raise()
{
	this->salary *= this->get_annual_raise_multiplier();
}
