//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Project.h"
#include "Personal.h"
#include "Interfaces.h"
#include <string>
#include <cstring>

class Engineer : public Personal, public ProjectBudget  {
 protected:
  Project* m_project;
  float m_part;

 public:
  Engineer(int id, std::string name, std::string position,
           int salary, Project* project, float part);
  int calcBonus() override;  // return 0
  void calc() override;
  void printinfo() override;
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;  // return 0
};

#endif  // INCLUDE_ENGINEER_H_
