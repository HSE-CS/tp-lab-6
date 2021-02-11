// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_ENGINEER_H_
#define TP_LAB_6_SRC_ENGINEER_H_

#include "Factory.h"
#include "Personal.h"
#include "Manager.h"

class Engineer : public Personal, IProjectBudget {
 private:
  Project *project;
 public:
  Engineer(int salary, Project *project) : Personal(salary), project(project) {}
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  int calcBase(int salary, int wtime) override;
  int calcBonus() override;
};

class Programmer : public Engineer {
 public:
  Programmer(int salary, Project *project);
  int calsProAdditions();
};

class Tester : public Engineer {
 public:
  Tester(int salary, Project *project);
  int calsProAdditions();
};

class TeamLeader : public Programmer, IHeading {
 public:
  TeamLeader(int salary, Project *project);
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  int calcBase(int salary, int wtime) override;
  int calcBonus() override;
  int calcHeads() override;
};

#endif //TP_LAB_6_SRC_ENGINEER_H_
