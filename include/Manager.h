// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include "Engineer.h"
#include "Interfaces.h"
#include "Employee.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
  Project *project = nullptr;

 public:
  ProjectManager(int id, std::string name, int worktime,
                 std::string position, int payment, Project* project);
  Project *getProject();
  int calc() override;
  int calcHeads() override;
  void printInfo() override;
  int calcBudgetPart(double part, int budget) override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, int worktime, std::string position,
                int payment, std::vector <Project*> project);
  void calc() override;
};

#endif  // INCLUDE_MANAGER_H_
