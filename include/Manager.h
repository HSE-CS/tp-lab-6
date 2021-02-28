// Copyright 2021 mkhorosh
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading{
 protected:
  Project f;

 public:
  void calcHeads();
  void calc();
};

class SeniorManager : public ProjectManager{
 protected:
  Project[2] h;

 public:
  void calc();
};

#endif  // INCLUDE_MANAGER_H_
