// Copyright 2021 Dev-will-work
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <iostream>
#include <string>
#include "Employee.h"
#include "Interfaces.h"


class ProjectManager : public Employee, public ProjectBudget, public Heading {
 public:
  ProjectManager(Project* projects, std::string fio, Position pos);
  virtual ~ProjectManager();
  virtual Project* getProject();
  virtual void printInfo();
  virtual int calcBudgetPart(float part, int budget);
  virtual int calcProAdditions();  // Interface implementation!
  virtual int calcHeads();
  virtual void calc();

 protected:
  Project* projects = nullptr;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(Project* projects, std::string fio, Position pos,
    size_t project_count);
  virtual ~SeniorManager();
  virtual void calc();
  virtual void printInfo();

 protected:
  size_t projects_count = 0;
};

#endif  // INCLUDE_MANAGER_H_
