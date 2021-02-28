// Copyright 2021 Schenikova
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <vector>
#include "Interfaces.h"
#include "Personal.h"

class Engineer: public ProjectBudget, public Personal {
 protected:
  Project project;
  float part;
  int pro;
  int percent;
 public:
  float calcBudgetPart(float part, int budget);
  void calc();
  void setPro(int pro);
  void setPercent(int percent);
  void printInfo();
  void setProject(Project project);
  unsigned int calcProAdditions();
};

class Tester: public Engineer {
 public:
  unsigned int calcProAdditions();
  void calc();
};

class Programmer: public Engineer {
 public:
  unsigned int calcProAdditions();
  void calc();
};

class TeamLeader: public Programmer, public Heading {
 private:
  std::vector<Programmer> programmers;
 public:
  unsigned int calcHeads();
  void setProgrammers(std::vector<Programmer> programmers);
  void calc();
};

#endif  // INCLUDE_ENGINEER_H_
