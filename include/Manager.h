// Copyright 2021 by Bodrov Egor
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Interfaces.h"
#include "Employee.h"
#include <vector>
#include <string>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project*> projects;
  float partition;

 public:
  ProjectManager(int id, std::string name, std::string pos,
                 std::vector<Project*> projects, float part);

  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  void calc() override;
  void printInfo();
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, std::vector<Project*> projects,
                float part);

  void calc() override;
};

#endif  // INCLUDE_MANAGER_H_
