// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_MANAGER_H_
#define TP_LAB_6_SRC_MANAGER_H_

#include <vector>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"

class ProjectManager : private Employee, IHeading {
 private:
  Project *project;
 public:
  int calcHeads();
  int calc();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project *> projects;
 public:
  int calc();
};

#endif //TP_LAB_6_SRC_MANAGER_H_
