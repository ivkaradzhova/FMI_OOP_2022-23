#include "Programmer.h"

Programmer::Programmer(std::string name, const unsigned int experience, const double salary, const std::string& language)
	: ITSpecialist(name, experience, salary), language(language)
{
}

Employee* Programmer::clone() const
{
	return new Programmer(*this);;
}

double Programmer::get_annual_raise_multiplier() const
{
	double avg_difficulty = get_avg_difficulty();

	if (avg_difficulty > 0 && avg_difficulty <= 4) {
		return 1.06;
	}
	else if (avg_difficulty > 4 && avg_difficulty <= 7) {
		return 1.12;
	}

	return 1.15;
}
