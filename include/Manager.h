// Copyright 2021 LongaBonga
#ifndef INCLUDE_MANAGER_H
#define INCLUDE_MANAGER_H

#include "Employee.h"
#include "Factory.h"
#include "Interfaces.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project *> projects;
  float part;

 public:
  ProjectManager(int id, const std::string name, std::string position,
                 int num_of_projects, int payment, int worktime,
                 const std::vector<Project *> &_projects, float part)
      : Employee(id, name, position, payment, worktime), part(part) {
    for (int i = 0; i < num_of_projects; i++) projects.push_back(_projects[i]);
  }
  void printInfo() override;
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  int calc() override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, const std::string name, std::string position,
                int num_of_projects, int payment, int worktime,
                const std::vector<Project *> &projects, float part)
      : ProjectManager(id, name, position, num_of_projects, payment, worktime,
                       projects, part) {}
};

#endif  // INCLUDE_MANAGER_H_
