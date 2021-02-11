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
  Project(int id, int budget) : id(id), budget(budget) {}
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

class ProjectManager : public Employee, IHeading {
 private:
  Project *project;
 public:
  ProjectManager(Project *project) : project(project) {}
  int calcHeads() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project *> projects;
 public:
  SeniorManager(Project *project, const std::vector<Project *> &projects)
      : ProjectManager(project), projects(projects) {}
  int calc();
};

#endif //TP_LAB_6_SRC_MANAGER_H_
