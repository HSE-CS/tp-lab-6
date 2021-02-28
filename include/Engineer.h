// Copyright 2021 mkhorosh
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include "Interfaces.h"
#include "Personal.h"
#include "Factory.h"

class Engineer : public ProjectBudget, public Personal{
 protected:
  Project f;

 public:
  void calcBudgetPart();
  void calc;
};

class Tester : public Engineer{
 public:
  void calcProAdditions();
};

class Programmer : public Engineer{
 public:
  void calcProAdditions();
};

class TeamLeader : public Programmer, public Heading{
 public:
  void calcHeads();
  void calc();
};

#endif  // INCLUDE_ENGINEER_H_
