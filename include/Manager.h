// Copyright 2021 mkhorosh
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"
#include <vector>
#include <string>

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project> projects;

 public:
  // constructor
  ProjectManager(std::string id, std::string name, Position position,
                 int work_time, int payment, std::vector<Project> projects)
      : Employee(id, name, position, work_time, payment), projects(projects) {}
  int calcHeads() override;
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  void calc() override;
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 protected:
  std::vector<Project> projects;
  float part;

 public:
  SeniorManager(std::string id, std::string name,
                Position position, int work_time, int payment,
                std::vector<Project> projects)
      : ProjectManager(id, name, position, work_time, payment,
                       projects) {}
};

#endif  // INCLUDE_MANAGER_H_
