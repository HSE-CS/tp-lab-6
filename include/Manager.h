// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_MANAGER_H_
#define TP_LAB_6_SRC_MANAGER_H_

#include <vector>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"

class Project {
 private:
  int id;
  int budget;
 public:
  int GetId() const {
    return id;
  }
  void SetId(int id) {
    Project::id = id;
  }
  int GetBudget() const {
    return budget;
  }
  void SetBudget(int budget) {
    Project::budget = budget;
  }
};

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
