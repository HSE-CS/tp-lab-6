// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include "Interfaces.h"
#include "Employee.h"
#include "Project.h"

class ProjectManager : public IProjectBudget, 
	public IHeading, public Employee {
 protected:
	std::vector<Project*>* projects;
 public:
	ProjectManager(int id, std::string name);
	std::vector<Project*>* getProjects() {
		return projects;
	}
	int calcBudgetPart(float part, int budget) override;
	int calcHeads() override;
	void calc() override;
	void printInfo() override;
	int calcProAdditions() override {
		return 0;
	}
};

class SeniorManager : public ProjectManager {
 public:
	SeniorManager(int id, std::string name);
	void calc() override;
	int calcProAdditions() override {
		return 0;
	}
};

#endif  INCLUDE_MANAGER_H_
