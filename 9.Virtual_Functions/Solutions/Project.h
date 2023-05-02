#ifndef _PROJECT_H
#define _PROJECT_H
#include <string>

class Project {
public:
	Project(std::string name = "", unsigned int difficulty = 0);
	int get_difficulty() const;

private:
	std::string name;
	unsigned int difficulty;
};

#endif 
