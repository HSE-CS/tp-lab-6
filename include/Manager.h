// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <utility>
#include <vector>
#include <string>
#include <iostream>
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

  int getId() const {
    return id;
  }

  int getBudget() const {
    return budget;
  }
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

  Project *getProject() {
    return project;
  }

  int calc() override {
    return getWorktime() * getPayment();
  }

  int calcHeads() override {
    return static_cast<int>(getProject()->getBudget() * 0.01);
  }

  void printInfo() override {
    std::cout << "Project Manager{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", project{id=" + std::to_string(project->getId())
        + ", budget=" + std::to_string(project->getBudget())
        + "} }" << std::endl;
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

  std::vector<Project *> &getProjects() {
    return projects;
  }

  std::string getProjectsAsString() {
    std::string string;
    for (Project *project : projects) {
      string += "id=" + std::to_string(project->getId())
          + ", budget=" + std::to_string(project->getBudget()) + " ";
    }
    return string;
  }

  int calc() override {
    return ProjectManager::calc();
  }

  int calcHeads() override {
    return static_cast<int>(ProjectManager::calcHeads() * 2);
  }

  void printInfo() override {
    std::cout << "Senior Manager{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", project{" + getProjectsAsString() + "} }" << std::endl;
  }
};

#endif  // INCLUDE_MANAGER_H_
