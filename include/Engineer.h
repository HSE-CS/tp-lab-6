// Copyright 2021 by Liza
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"
#include <string>

class Engineer : public Personal {
private:
	Project project;
public:
	Engineer(int _id, std::string _name, std::string _pos,
		int _payment, Project currentProject);
	Project getProject();
	int calcBudgetPart(double part, int budget);
	int calcProAdditions();
	int calc();
};

class Programmer : public Engineer {
public:
	Programmer(int _id, std::string _name, std::string _pos,
		int _payment, Project currentProject);
	int calcProAdditions();
};

class Tester : public Engineer {
public:
	Tester(int _id, std::string _name, std::string _pos,
		int _payment, Project currentProject);
	int calcProAdditions();
};

class TeamLeader : public Programmer {
public:
	TeamLeader(int _id, std::string _name, std::string _pos,
		int _payment, Project currentProject);
	int calcHeads();
	int calc();
};

#endif  // INCLUDE_ENGINEER_H_
