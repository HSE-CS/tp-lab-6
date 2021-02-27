// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Interfaces.h"

#include <string>
#include <iostream>

class Project {
 public:
  explicit Project(int id, int budget);
  int id;
  int budget;
};

class Engineer: public Personal, ProjectBudget {
 public:
  Engineer(int id, std::string name, std::string position, int worktime,
           int payment, Project *project)
      : Personal(id, name, position, worktime, payment), project(project) {}

  int calc() override;
  int calcBase(int, int) override;
  int calcBonus() override;
  int calcBudgetPart(float, int) override;
  int calcProAdditions() override;

  void printInfo() override;

  Project *getProject();

 private:
  Project *project;
};

class Tester: public Engineer {
 public:
  Tester(int id, std::string name, std::string position, int worktime,
         int payment, Project *project)
      : Engineer(id, name, position, worktime, payment, project) {}
  int calc() override;
  int calcBase(int, int) override;
  int calcBonus() override;
  int calcBudgetPart(float, int) override;
  int calcProAdditions() override;

  void printInfo() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, std::string position, int worktime,
         int payment, Project *project)
      : Engineer(id, name, position, worktime, payment, project) {}
  int calc() override;
  int calcBase(int, int) override;
  int calcBonus() override;
  int calcBudgetPart(float, int) override;
  int calcProAdditions() override;

  void printInfo() override;
};

class TeamLeader : public Programmer, Heading {
 public:
  TeamLeader(int id, std::string name, std::string position, int worktime,
             int payment, Project *project)
      : Programmer(id, name, position, worktime, payment, project) {}
  int calc() override;
  int calcBase(int, int) override;
  int calcBonus() override;
  int calcBudgetPart(float, int) override;
  int calcProAdditions() override;
  int calcHeads() override;

  void printInfo() override;
};

#endif  // INCLUDE_ENGINEER_H_
