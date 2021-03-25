// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 protected:
    std::vector <Project*> projects;
    int bonus = 1;
    int calcHeads() override;
    int calcProAdditions();
    int calcBudgetPart() override;
 public:
    ProjectManager(int id, std::string name,
                   int wt, Positions position, std::vector <Project *> p);
    void printInfo() override;
    int calc() override;
};

class SeniorManager : public ProjectManager {
 protected:
    std::vector<Project *> projects;
 public:
    SeniorManager(int id, const std::string& name,
                  int workTime, Positions position, std::vector<Project *> p);
};


#endif  // INCLUDE_MANAGER_H_
