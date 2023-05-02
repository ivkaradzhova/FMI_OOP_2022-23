#include "Project.h"

Project::Project(std::string name, unsigned int difficulty): name(name), difficulty(difficulty)
{
	if (this->difficulty == 0 || this->difficulty > 10) {
		throw std::exception("The difficulty is not valid: must be between 1 and 10!");
	}

}

int Project::get_difficulty() const
{
	return this->difficulty;
}
