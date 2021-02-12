// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <utility>
#include <vector>
#include <string>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"

class Project {
 private:
  int id;
  int budget;

 public:
  Project(int id,
          int budget)
      : id(id),
        budget(budget) {}
};

class ProjectManager : public Employee, IHeading {
 private:
  Project *project;

 public:
  ProjectManager(int id,
                 const std::string &name,
                 const std::string &position,
                 int payment,
                 Project *project)
      : Employee(id, name, position, payment),
        project(project) {}

  void printInfo() override {
  }

  int calcHeads() override {
    return 0;
  }

  int calc() override {
    return 0;
  }
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project *> projects;

 public:
  SeniorManager(int id,
                const std::string &name,
                const std::string &position,
                int payment,
                Project *project,
                std::vector<Project *> projects)
      : ProjectManager(id, name, position, payment, project),
        projects(std::move(projects)) {}

  void printInfo() override {
    ProjectManager::printInfo();
  }

  int calcHeads() override {
    return ProjectManager::calcHeads();
  }

  int calc() override {
    return 0;
  }

  std::vector<Project *> &getProjects() {
    return projects;
  }
};

#endif  // INCLUDE_MANAGER_H_
