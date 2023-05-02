#include "QA.h"

QA::QA(std::string name, const unsigned int experience, const double salary, const bool is_automation)
	: ITSpecialist(name, experience, salary), is_automation(is_automation)
{
}

Employee* QA::clone() const
{
	return new QA(*this);;
}

double QA::get_annual_raise_multiplier() const
{
	return this->is_automation ? get_automation_multiplier() : get_manual_multiplier();
}

double QA::get_manual_multiplier() const
{
	unsigned int project_count = get_project_count();

	if (project_count <= 1) {
		return 1.05;
	}
	else if (project_count > 1 && project_count <= 3) {
		return 1.1;
	}

	return 1.15;
}

double QA::get_automation_multiplier() const
{
	double avg_difficulty = get_avg_difficulty();

	if (avg_difficulty > 0 && avg_difficulty <= 4) {
		return 1.05;
	}
	else if (avg_difficulty > 4 && avg_difficulty <= 7) {
		return 1.1;
	}

	return 1.15;
}
