#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include "Interfaces.h"
#include <iostream>
#include <string>

class ProjectManager : public Employee, public ProjectBudget, public Project, public Heading{
protected:
	Project project;
public:
	ProjectManager(unsigned int id, std::string name, Position position, std::string project);
	unsigned int calcHeads();
	void calc();
	unsigned int calcProAdditions();
	unsigned int calcBudgetPart(double part, unsigned int budget);
	void printInfo();
};




class SeniorManager : public ProjectManager{
protected:
	Project project;
public:
	SeniorManager(unsigned int id, std::string name, Position position, std::string project);
	void calc();
	unsigned int calcBudgetPart(double part, unsigned int budget);
};

#endif