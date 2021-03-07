// Copyright 2021 Urtyukov Ilya
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
  ProjectManager(int, const std::string, std::string,int, int, int, const std::vector<Project *> &)
  int calcHeads();
  int calc();
  int calcProAdditions();
  void printInfo();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project> project;

 public:
  SeniorManager(int, std::string, std::string, int, int, int, const std::vector<Project *> &)
  int calc();
  void printInfo();
};
#endif  // INCLUDE_MANAGER_H_
