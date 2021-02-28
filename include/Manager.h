// Copyright 2021 Schenikova
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager: public Heading, public ProjectBudget, public Employee {
 protected:
  std::vector <Project> projects;
  int numOfHeads;
  int percent;
  float part;
 public:
  unsigned int calcHeads();
  void calc();
  void setPercent(int percent);
  void setNum(int numOfHeads);
};

class SeniorManager: public ProjectManager {
 public:
  void calc();
};

#endif  // INCLUDE_MANAGER_H_
