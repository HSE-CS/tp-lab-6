// Copyright 2021 Elise
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <iostream>
#include <string>
#include <vector>

#include "Engineer.h"
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Heading, public Employee, public ProjectBudget {
 private:
  std::vector<Project*> project;

 public:
  ProjectManager(int id, const std::string name, std::string position,
                 int num_of_projects, int payment, int worktime,
                 const std::vector<Project *> &_projects)
      : Employee(id, name, position, payment, worktime) {
    for (int i = 0; i < num_of_projects; i++) project.push_back(_projects[i]);
  }
  int calcBudgetPart(float part, int budget);
  int calcHeads();
  int calc();
  int calcProAdditions();
  void printInfo();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project> project;

 public:
  SeniorManager(int id, std::string name, std::string position,
                int num_of_projects, 
                int worktime, int payment, std::vector<Project*> &project)
      : ProjectManager(id, name, position, num_of_projects, payment, worktime,
                       project) {}
  int calc();
  void printInfo();
};
#endif  // INCLUDE_MANAGER_H_