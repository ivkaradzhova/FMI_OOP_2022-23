#ifndef _QA_H
#define _QA_H
#include <string>
#include "ITSpecialist.h"

class QA : public ITSpecialist {
public:
	QA(std::string name, const unsigned int experience, const double salary, const bool is_automation);
	Employee* clone() const override;

private:
	bool is_automation;

	double get_annual_raise_multiplier() const override;
	double get_manual_multiplier() const;
	double get_automation_multiplier() const;
};

#endif
