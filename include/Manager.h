// Copyright 2021 JGMax

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee,
        public ProjectBudget, public Heading{
 protected:
    std::vector<Project*> projects;

 public:
    ProjectManager(int id,
                   std::string fullName,
                   int workTime,
                   Position position,
                   Project* project);
    int calcHeads() override;
    int calcBudgetPart() override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() override;
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(int id,
                  std::string fullName,
                  int workTime,
                  Position position,
                  std::vector<Project*> projects);
    int calcBudgetPart() override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() override;
    int calcHeads() override;
};

#endif  // INCLUDE_MANAGER_H_
