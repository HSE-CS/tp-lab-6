#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>

class Project {
public:
	std::string id;
	unsigned int budget;
};

class WorkBaseTime {
public:
	virtual unsigned int calcBase(unsigned int salary, unsigned int wtime) = 0;
	virtual unsigned int calcBonus() = 0;
};

class ProjectBudget {
public:
	virtual unsigned int calcBudgetPart(double part, unsigned int budget) = 0;
	virtual unsigned int calcProAdditions() = 0;
};

class Heading {
public:
	virtual unsigned int calcHeads() = 0;
};

#endif
