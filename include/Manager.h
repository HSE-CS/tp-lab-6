// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include <vector>
#include "Engineer.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
  Project* project;
  int subordinates = 0;

 public:
  ProjectManager(int id, std::string name, Project* project, int sub)
     : Employee(id, name) {
     this->project = project;
     this->subordinates = sub;
     pos = PROJECTMANAGER;
  }
  int getSubbordinates();
  virtual int calcHeads();
  virtual void calc();
  virtual void printInfo();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int id, std::string name, Project* project, int sub)
     : ProjectManager(id, name, project, sub) {
     pos = SENIORMANAGER;
  }
  void addProject(Project* p);
  virtual void calc();
};

#endif  // INCLUDE_MANAGER_H_
