//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include "Factory.h"
#include "Interfaces.h"
#include "Employee.h"

class ProjManager : public Employee, Heading, ProjectBudget {
 public:
  explicit ProjManager(int id, const std::string &name,
                       const std::string &position,
                       Project *project)
      : Employee(id, name, position),
        project(project) {}

  ProjManager(int id, const std::string &name,
              const std::string &position)
      : Employee(id, name, position) {}
  /* Salary calculations */
  int calc() override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  /* Getters */
  Project *getProject();
  /* Print */
  void printInfo() override;

 private:
  Project *project = nullptr;
};

class SeniorManager : public ProjManager {
 public:
  explicit SeniorManager(int id,
                         const std::string &name,
                         const std::string &position,
                         std::vector<Project *> projects)
      : ProjManager(id, name, position),
        projects(std::move(projects)) {}
  /* Salary calculations */
  int calc() override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  /* Getters */
  std::string getStrProjs();
  /* Print */
  void printInfo() override;

 private:
  std::vector<Project *> projects;
};

#endif  //  INCLUDE_MANAGER_H_
