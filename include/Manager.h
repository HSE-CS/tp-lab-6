// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>

#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"
#include <string>

class ProjectManager : public Employee, Heading {
 public:
  explicit ProjectManager(int id, std::string name, std::string position,
    int workTime, int payment, std::vector <Project*> projects)
    :Employee(id, name, position, workTime, payment) {
    this->projects = projects;
  }
  ~ProjectManager();
  std::vector <Project*> getProjects();
  int calc() override;
  int calcBudgetPart(float part, int budget);
  int calcHeads() override;
  int calcProAdditions();
  void printInfo() override;
 private:
  std::vector<Project*> projects;
};

class SeniorManager : public ProjectManager {
 public:
  explicit SeniorManager(int id, std::string name, std::string position,
    int workTime, int payment, std::vector <Project*> projects)
    : ProjectManager(id, name, position, workTime, payment, projects) {}
  ~SeniorManager();
  int calc() override;
  void printInfo() override;
 private:
  std::vector<Project*> projects;
};

#endif  //  INCLUDE_MANAGER_H_
