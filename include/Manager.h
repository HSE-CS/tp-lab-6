// Copyright 2021 MalininDmitry

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include <vector>
#include "Interfaces.h"
#include "Employee.h"
#include "Factory.h"

class ProjectManager : public IProjectBudget, public IHeading, public Employee {
 protected:
    std::vector<Project *> projects;
    float part;
 public:
    ProjectManager(int id, std::string name,
                   std::string position, int numProjects,
                   const std::vector<Project *> &projects,
                   float part, int salary);
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;
    void calc() override;
    void printInfo() override;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int id, std::string name, std::string position,
                  int numProjects,
                  const std::vector<Project *> &projects,
                  float part, int salary);
};
#endif  // INCLUDE_MANAGER_H_

