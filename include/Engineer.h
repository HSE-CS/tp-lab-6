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

 public:
  Project(int, double);
  int getId();
  double getBudget();
};

class Engineer : public ProjectBudget, public Personal {
 private:
  Project *project;

 public:
  Engineer(int id, std::string name, int worktime,
           std::string position, int payment, Project* project);
  Project *getProject();
  int calc() override;
  int calcBonus() override;
  int calcBase(int salary, int wtime) override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  void printInfo() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, int worktime,
             std::string position, int payment, Project* project);
  int calcProAdditions() override;
};

class Tester : public Engineer {
 public:
  Tester(int id, std::string name, int worktime,
         std::string position, int payment, Project* project);
  int calcProAdditions() override;

class TeamLeader : public Programmer, public Heading {
 public:
  int calc() override;
  int calcHeads() override;
};

#endif  // INCLUDE_ENGINEER_H_
