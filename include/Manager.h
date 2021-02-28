// Copyright 2021 Pavlova D.

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>

class Project {
 private:
  int id;
  std::string name;

 public:
  int Budget;
  int team;
  Project(int id, std::string name, int budget)
      : id(id), name(name), Budget(budget), team(0) {}
};

class ProjectManager : public Employee, public IHeading, public IProjectBudget {
 private:
  std::vector<Project *> allProjects;
  float part;

 public:
  ProjectManager(int id, std::string name, Position position,
                 std::vector<Project *> myProject, float part, int _salary)
      : Employee(id, name, position, _salary),
        allProjects(std::move(myProject)), part(part) {}

  int calcHeads() override;
  int calcBudgetPart(float _part, int _budget) override;
  int calcProAdditions() override;
  void calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project *> allProjects;
  float part;

 public:
  SeniorManager(int id, std::string name, Position position,
                std::vector<Project *> _allProjects, float part, int _salary)
      : ProjectManager(id, name, position, std::move(_allProjects), part,
                       _salary),
        part(part){}
};

#endif  // INCLUDE_MANAGER_H_
