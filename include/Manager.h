// Copyright 2021 Tatsenko Alexey
#pragma once
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading {
 private:
  std::string name;
  std::vector<Project*> projects;

 public:
  ProjectManager(int id, std::string fi, Position position,
                 std::vector<Project*> project, std::string name);
  ProjectManager(int id, std::string fi, Position position,
                 std::vector<Project*> project)
      : Employee(id, fi, position) {
    projects = project;
  }
  int calc_heads() override;
  void calc() override;
  void print_info() override;
  Project* get_project();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int id, std::string fi, Position position,
                std::vector<Project*> projects);
  void print_info() override;
  void calc() override;
};
