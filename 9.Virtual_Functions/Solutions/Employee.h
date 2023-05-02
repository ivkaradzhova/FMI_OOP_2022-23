#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>

class Employee {
public:
	Employee(std::string name, const unsigned int experience, const double salary);
	virtual ~Employee() = default;
	double get_salary() const;
	void annual_raise();
	virtual Employee* clone() const = 0;

protected:
	virtual double get_annual_raise_multiplier() const = 0;

private:
	std::string name;
	unsigned int experience;
	double salary;
};

#endif