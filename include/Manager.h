// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>
#include <vector>

class Project {
 private:
  std::string id;
 public:
  Project(std::string id, double budget) : id(id), budget(budget) {}
  double budget;
};

class ProjectManager : public Employee, public IProjectBudget, public IHeading {
 private:
  std::vector<Project*> projects;
 public:
  ProjectManager(std::string id,
    std::string name,
    double salary,
    Position position,
    std::vector<Project*> projects)
    : Employee(id, name, salary, position) {
    this->projects = projects;
  }
  int calcHeads() override;
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  void calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;
 public:
  SeniorManager(std::string id,
    std::string name,
    double salary,
    Position position,
    std::vector<Project*> projects)
    : ProjectManager(id, name, salary, position, projects) {}
  void calc() override;
};

#endif  // INCLUDE_MANAGER_H_
