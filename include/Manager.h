// Copyright 2021 Shirokov Alexander
#pragma once

#include <iostream>

#include "Interfaces.h"
#include "Employee.h"
#include <vector>
#include <string>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project*> projects;
  float partition;

 public:
  ProjectManager(int id, std::string name, Position position,
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
  Position position, float part);
  void calc() override;
};
