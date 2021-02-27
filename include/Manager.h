// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Interfaces.h"
#include "Employee.h"
#include "Engineer.h"

#include <string>
#include <vector>
#include <iostream>

class ProjectManager: public Emploeey, ProjectBudget, Heading {
 public:
  ProjectManager(int id, std::string name, std::string position, int worktime,
                 int payment, std::vector<Project*> projects)
      : Emploeey(id, name, position, worktime, payment), projects(projects) {}

  int calc() override;
  int calcBudgetPart(float, int) override;
  int calcProAdditions() override;
  int calcHeads() override;

  void printInfo() override;

  Project *getProject(int);

 private:
  std::vector<Project*> projects;
};

class SeniorManager: public ProjectManager {
 public:
  SeniorManager(int id, std::string name, std::string position, int worktime,
                int payment, std::vector<Project*> projects, int id_project)
      : ProjectManager(id, name, position, worktime, payment, projects),
      id_project(id_project) {}

  int calc() override;
  void printInfo() override;

 private:
  int id_project;
};

#endif  // INCLUDE_MANAGER_H_
