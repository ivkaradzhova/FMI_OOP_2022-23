#ifndef _ITSPECIALIST_H
#define _ITSPECIALIST_H
#include <string>
#include "Employee.h"
#include "Project.h"

class ITSpecialist : public Employee {
public:
	ITSpecialist(std::string name, const unsigned int experience, const double salary);
	ITSpecialist(const ITSpecialist& other);
	ITSpecialist(ITSpecialist&& other);
	ITSpecialist& operator=(const ITSpecialist& other);
	ITSpecialist& operator=(ITSpecialist&& other);
	~ITSpecialist();
	double get_avg_difficulty() const;
	unsigned int get_project_count() const;
	bool add_project(Project& project);

private:
	Project** projects;
	unsigned int size;
	unsigned int capacity;

	void copy(const ITSpecialist& other);
	void move(ITSpecialist&& other);
	void resize();
};

#endif