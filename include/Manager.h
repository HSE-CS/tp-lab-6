// Copyright 2020 S. BOR
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"

class ProjectManager: public Employee, public ProjectBudget, public Heading {
 protected:
  Project* projects;
 
 public:
  unsigned calcProAdditions();
  void printInfo();
  unsigned calcHeads(int numberOfWorkers);
  unsigned calcBudgetPart(float part, int budget);
  void calc();
};

class SeniorManager:  public ProjectManager {
 private:
  int numberOfProjects;

 public:
  void clac();
};


#endif  // INCLUDE_MANAGER_H_
