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
  std::vector <Project*> projects;

 public:
  ProjectManager(int id, std::string name, std::string position,
                 int payment, std::vector <Project*> projects);
  Project *getProject();
  std::vector <Project*> getProjects();
  int calc() override;
  int calcHeads(int) override;
  void printInfo() override;
  int calcBudgetPart(float part, int budget) override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, std::string position,
                int payment, std::vector <Project*> project);
  int calc() override;
};

#endif  // INCLUDE_MANAGER_H_
