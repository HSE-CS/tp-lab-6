// Copyright DB 2021
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"


class ProjectManager : public Employee, public ProjectBudget, public Heading {
 private:
  std::vector<Project*> projects;
  double part;

 public:
  ProjectManager(int id, const std::string &name, Position position,
                 int numprojects, const std::vector<Project *> &projects,
                 float part);
  int calcBudgetPart(float part,
                              int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  void calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  SeniorManager(int id, const std::string &name, Position position,
                 int numprojects,
                const std::vector<Project *> &projects, float part);
};

#endif  // INCLUDE_MANAGER_H_