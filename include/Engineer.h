// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Interfaces.h"
#include "Employee.h"

class Project {
 private:
  int id;
  double budget;
  int count = 0;

 public:
  Project(int, double);
  int getId();
  double getBudget();
  int getCount();
  void setCount();
};

class Engineer : public ProjectBudget, public Personal {
 private:
  Project *project;

 public:
  Engineer(int id, std::string name, int payment, int salary,
           std::string position, Project* project);
  Project *getProject();
  int calc();
  int calcBudgetPart(float part, int budget);
  void printInfo();
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, int salary,
             std::string position, int payment, Project* project);
  int calc();
  int calcProAdditions();
};

class Tester : public Engineer {
 public:
  Tester(int id, std::string name, int salary,
         std::string position, int payment, Project* project);
  int calc();
  int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, int salary,
             std::string position, int payment, Project* project);
  int calc();
  int calcHeads();
};

#endif  // INCLUDE_ENGINEER_H_
