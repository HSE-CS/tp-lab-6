// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Interfaces.h"

class Employee;
class Project;
class ProjectBudget;
class Heading;

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 protected:
  std::vector<Project *> projects;
  double part;
  size_t subordinates_num;

 public:
  ProjectManager();
  ProjectManager(int _id, std::string _name, int _sub_num, Project *_project,
                 double _part);
  unsigned int calcHeads() override;
  unsigned int calcBudgetPart(double part, unsigned int budget) override;
  void calc() override;
  void printInfo() override;
  unsigned int calcProAdditions() override;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int _id, std::string _name, int _sub_num,
                const std::vector<Project *> &_projects, double _part);
  void calc() override;
};

#endif  // INCLUDE_MANAGER_H_
