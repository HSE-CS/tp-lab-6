// Copyright 2021 Ksuvot
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include <vector>
#include "Engineer.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
  Project* project;

 public:
  ProjectManager(int id, std::string name, Project* project, int sub)
      : Employee(id, name) {
    this->project = project;
    setPosition(projectmanager);
  }
  virtual int calcHeads();
  virtual void calc();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int id, std::string name, Project* project, int sub)
      : ProjectManager(id, name, project, sub) {
    setPosition(seniormanager);
  }
  virtual void calc();
};

#endif  // INCLUDE_MANAGER_H_
