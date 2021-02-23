// Copyright 2021 Smirnov Grigory
#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "Engineer.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
  Project& project;
  int subordinates = 0;

 public:
  int getSubbordinates();
  virtual int calcHeads();
  virtual void calc();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  virtual void calc();
};

#endif
