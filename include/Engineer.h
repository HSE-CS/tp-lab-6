// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_ENGINEER_H_
#define TP_LAB_6_SRC_ENGINEER_H_

#include "Factory.h"
#include "Personal.h"

class Engineer : private Personal, IProjectBudget {
 private:
  Project *project;
 public:
  int calcBudgetPart();
  int calc();
};

class Programmer : private Engineer {
 public:
  int calsProAdditions();
};

class Tester : private Engineer {
 public:
  int calsProAdditions();
};

class TeamLeader : private Programmer, IHeading {
 public:
  int calcHeads();
  int calc();
};

#endif //TP_LAB_6_SRC_ENGINEER_H_
