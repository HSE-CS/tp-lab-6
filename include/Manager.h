// Copyright 2021 Galex

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "../include/Employee.h"
#include "../include/Interfaces.h"
#include "../include/Project.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 private:
  std::vector<Project *> projects;

 public:
  ProjectManager(int id, std::string name, std::vector<Project *> projects);
  double calcHeads() override;
  std::vector<Project* > getProjects();
  void calc() override;
  double calcBudgetPart(double part, int budget) override;
  void printInfo() override;
  void calcProAdditions() override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, std::vector<Project *> projects);
  void calc() override;
};
#endif  // INCLUDE_MANAGER_H_
