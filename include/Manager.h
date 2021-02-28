// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include "Interfaces.h"
#include "Employee.h"
#include <vector>
#include <string>

class Project {
 public:
    int id;
    int budget;
    Project(int id, int budget);
};

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 public:
    void calc() override;
    void printInfo() override;
    int calcHeads() override;
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    ProjectManager(int id, std::string name, Position position,
        int worktime, std::vector <Project*> projects);
 protected:
    std::vector<Project*> projects;
};

class SeniorManager : public ProjectManager {
 public:
    void calc() override;
    SeniorManager(int id, std::string name, Position position,
        int worktime, std::vector <Project*> projects);
};

#endif  // INCLUDE_MANAGER_H_
