// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <vector>
#include "Employee.h"
#include "Project.h"
#include "Interfaces.h"
class ProjectManager : public Employee, public Heading, public ProjectBudget {
 protected:
  std::vector <Project*> projects;
  double salary;
 public:
  ProjectManager(unsigned int id, std::string name,
    int worktime, int position, double salary, std::vector <Project*> pr);
  int calcHeads();
  void calc();
  void printInfo();
  int calcBudgetPart();
  int calcProAdditions(int bonus);
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(unsigned int id, std::string name,
    int worktime, int position, double salary, std::vector <Project*> pr);
  void calc();
};

#endif  // INCLUDE_MANAGER_H_



