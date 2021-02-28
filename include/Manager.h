//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"
#include <vector>
#include <string>
#include <cstring>

class ProjectManager : public Heading, public ProjectBudget,
                       public Employee {
 protected:
  float pm_part;
  Project* pm_project;

 public:
  explicit ProjectManager(int id, std::string name,
                          std::string position, Project* project, float part);
  int calcHeads() override;
  int calcBudgetPart(float path, int budget) override;
  int calcProAdditions() override;  // return 0
  void calc() override;
  void printinfo() override;
};
class SeniorManager : public ProjectManager {
 protected:
  std::vector<Project*> sm_projects;

 public:
  explicit SeniorManager(int id, std::string name, std::string position,
                         Project* project, float part,
                         std::vector<Project*> projects);
  int calcHeads() override;
  int calcBudgetPart(float part, int budget) override;
  void calc() override;
  void printinfo() override;
};

#endif  // INCLUDE_MANAGER_H_

