// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>

#include "Employee.h"
#include "Interfaces.h"

//=============================================

class ProjectManager : public Employee, public ProjectBudget, public Heading {
 protected:
  std::vector<project_t*> projects;
  uint32_t calcHeads();
  uint32_t calcProAdditions() { return 0; };
  uint32_t calcBudgetPart(double part, uint32_t budget);

 public:
  ProjectManager(uint32_t id, std::string& name,
                 std::vector<project_t*>& projects);
  void calc();
  void printInfo();
};

//=============================================

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(uint32_t id, std::string& name,
                std::vector<project_t*>& projects);
  void calc();
};

#endif  // INCLUDE_MANAGER_H_
