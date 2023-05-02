#include "Manager.h"

Manager::Manager(std::string name, const unsigned int experience, const double salary, const unsigned int number_managed)
	: Employee(name, experience, salary), number_managed(number_managed)
{
}

Employee* Manager::clone() const
{
	return new Manager(*this);
}

double Manager::get_annual_raise_multiplier() const
{
	if (number_managed > 0 && number_managed <= 10) {
		return 1.06;
	}
	else if (number_managed > 10 && number_managed <= 15) {
		return 1.12;
	}

	return 1.15;
}
