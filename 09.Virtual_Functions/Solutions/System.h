#ifndef _SYSTEM_H
#define _SYSTEM_H
#include <vector>
#include "Employee.h"
#include "Project.h"

class System {
public:
	System();
	System(const System& other);
	System(System&& other);
	System& operator=(const System& other);
	System& operator=(System&& other);
	~System();
	bool add_employee(const Employee& employee);
	void add_project(Project project);
	void annual_raises();

private:
	double annual_budget;
	Employee** employees;
	unsigned int size;
	unsigned int capacity;
	std::vector<Project> projects;

	void copy(const System& other);
	void move(System&& other);
	void free();
	void resize();
};

#endif
