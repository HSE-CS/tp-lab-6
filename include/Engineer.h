// Copyright 2020 S. BOR
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"

class Engineer: public Personal, public ProjectBudget {
 protected:
  Project project;

 public:
  void printInfo();
  unsigned calcBonus(unsigned overtimeJob, unsigned cost);
  unsigned calcBudgetPart(float part, int budget);
  void calc();
};

class Programmer: public Engineer {
 public:
  unsigned calcProAdditions();
  void calc();
};

class Tester: public Engineer {
 public:
  unsigned calcProAdditions();
  void calc();
};

class TeamLeader: public Programmer, public Heading {
 public:
  unsigned calcHeads(int numberOfWorkers);
  void calc();
};

#endif  // INCLUDE_ENGINEER_H_
