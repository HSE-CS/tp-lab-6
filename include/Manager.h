#pragma once
#include <string>
#include <vector>

#include "Employee.h"
#include "Interfaces.h"

const uint32_t MANAGER_PER_HEAD = 10;
const uint32_t MANAGER_PRO_ADDITIONS = 15;

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<Project> projects;

 public:
  void calc() override;
  uint32_t calcHeads() override;
  uint32_t calcBudgetPart(float part, uint32_t buget) override;
  uint32_t calcProAdditions() override;
  void printInfo();
  ProjectManager(const uint32_t& id, const std::string& firstname,
                 const std::string& surname, Project project)
      : Employee(id, firstname, surname) {
    projects.push_back(project);
  }
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(const uint32_t& id, const std::string& firstname,
                const std::string& surname, std::vector<Project> projects)
      : ProjectManager(id, firstname, surname, projects.front()) {
    this->projects = projects;
  }
  void calc() override;
};
