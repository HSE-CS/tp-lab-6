//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager :
public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project*> projects;

 public:
  ProjectManager(int id, std::string name, Project* project)
  :Employee(id, name, Position::ProjectManager) {
    this->projects.push_back(project);
  }
  unsigned calcHeads() override;
  unsigned calc() override;
  unsigned calcBudgetPart(float part, unsigned budget) override;
  unsigned calcProAdditions() override;
  void setProject(Project* project);
  Project* getProject();
  void printInfo() override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name,
                std::vector<Project*> projects)
  :ProjectManager(id, name, nullptr) {
    this->position = Position::SeniorManager;
    this->projects = projects;
  }
  void setProject(std::vector<Project*> projects);
  Project* getProject(unsigned index);
  void printInfo() override;
};

#endif  // INCLUDE_MANAGER_H_
