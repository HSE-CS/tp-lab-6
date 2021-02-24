// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Engineer.h"
#include "Interfaces.h"
#include "Employee.h"

class ProjectManager: public ProjectBudget, public Heading, public Employee {
 private:
    std::vector<Project> project;

 public:
    ProjectManager(int id, std::string name, std::string pos, int worktime, int payment, std::vector<Project> project_)
        :Employee(id, name, pos, worktime, payment), project(project_) {};
    int calcHeads() override;
    int calc() override;
    void printInfo() override;
    int calcBudgetPart(float part, int budget);
    int calcProAdditions();
};

class SeniorManager : public ProjectManager {
 private:
    std::vector<Project> project;

 public:
    SeniorManager(int id, std::string name, std::string pos, int worktime, int payment, std::vector<Project> project_)
        :ProjectManager(id, name, pos, worktime, payment, project_) {};
    int calc() override;
    void printInfo() override;
};
#endif  // INCLUDE_MANAGER_H_
