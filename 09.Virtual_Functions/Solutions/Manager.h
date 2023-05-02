#ifndef _MANAGER_H
#define _MANAGER_H
#include "Employee.h"

class Manager : public Employee {
public:
	Manager(std::string name, const unsigned int experience, const double salary, const unsigned int number_managed);
	Employee* clone() const override;

private:
	unsigned int number_managed;

	double get_annual_raise_multiplier() const override;
};

#endif
