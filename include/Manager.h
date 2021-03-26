// Copyright 2020 Uskova
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"

class Project;

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
  Project* project;

 public:
  ProjectManager(int, std::string, Position, Project*);
  int calcHeads() override;
  int calcBudgetPart(float, int) override;
  void calc() override;
  void printinfo() override;
  int calcProAdditions() override;
  void setProject(Project*);
  Project* getProject();
  std::string getProjectName();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int, std::string, Position, Project*);
  void calc() override;
  void addProject(Project*);
  std::string getProjectsName();
  void printinfo() override;
  int calcWorkers();
};

#endif  // INCLUDE_MANAGER_H_
