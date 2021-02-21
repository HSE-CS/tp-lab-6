// Copyright 2021 valvarl

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"
#include <string>


class ProjectManager : public Employee, public IProjectBudget, public IHeading {
 protected:
    std::vector<Project*> projects;
    float part;
 public:
    ProjectManager(int id, const std::string &name, Position position,
                   int num_of_projects, const std::vector<Project *> &projects,
                   float part);
    void printInfo() override;
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;
    void calc() override;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int id, const std::string &name, Position position,
                  int num_of_projects, const std::vector<Project *> &projects,
                  float part);
};


#endif  // INCLUDE_MANAGER_H_
