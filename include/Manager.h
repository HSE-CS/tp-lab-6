// Copyright 2021 Danyaev Artem
#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager: public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector <Project*> projects;
  int calcHeads();
  int calcProAdditions();
  int calcBudgetPart(float part, int budget);
 public:
  ProjectManager(unsigned int id_, std::string& name_, Position pos, Project* project_);
  void calc();
  void printInfo();

};

class SeniorManager: public ProjectManager{
 protected:
  int calcHeads();

 public:
  SeniorManager(unsigned int id_, std::string& name_, Position pos, std::vector <Project*> &projects_);
  void calc();

};
