// Copyright 2021 Lab_6 TiNa
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include "Employee.h"
#include "Factory.h"
#include "Interfaces.h"
#include <iostream>
#include <string>
#include <vector>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project*> projects;
  float contrib;

 public:
  ProjectManager(int id, std::string name, std::string position, int numProj,
                 int worktime, int payment, const std::vector<Project *> &projects,
                 float contribIn)
      : Employee(id, name, position, worktime, payment), contrib(contribIn) {}
  float calcBudgetPart(float contrib, int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  int calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, std::string position, int numProj,
                int worktime, int payment, const std::vector<Project *> &projects,
                float contrib)
      : ProjectManager(id, name, position, numProj, worktime, payment, projects,
                       contrib) {}
};

#endif  // INCLUDE_MANAGER_H_
