// Copyright 2021 Tatsenko Ilya
#pragma once
#include <vector>
#include<string>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public IHeading {
 private:
  int n;
  std::vector<Project*> projects;

 public:
  ProjectManager(int id, std::string name, std::string position,
                 std::vector<Project*> project, int n)
      : Employee(id, name, position), n(n) {
    projects = project;
  }
  ProjectManager(int id, std::string name, std::string position,
                 std::vector<Project*> project)
      : Employee(id, name, position) {
    projects = project;
  }
  int calcHeads() override;
  void calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int id, std::string name, std::string position,
                std::vector<Project*> projects)
      : ProjectManager(id, name, position, projects) {
    this->projects = projects;
  }
  void printInfo() override;
  void calc() override;
};

