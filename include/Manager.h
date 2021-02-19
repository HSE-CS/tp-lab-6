#pragma once
#include <vector>

#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  Project* projects;

 public:
  void calc() override;
  uint32_t calcHeads() override;
  uint32_t calcBudgetPart(float part, uint32_t buget) override;
  uint32_t calcProAdditions() override;
  void printInfo() override;
  ProjectManager(const uint32_t& id, const std::string& firstname,
                 const std::string& surname)
      : Employee(id, firstname, surname) {}
};

class SeniorManager : public ProjectManager {
 protected:
  uint32_t num_projects;

 public:
  SeniorManager(const uint32_t& id, const std::string& firstname,
                const std::string& surname)
      : ProjectManager(id, firstname, surname) {}
  void calc() override;
};
