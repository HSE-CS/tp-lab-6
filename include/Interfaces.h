// Copyright 2021 Schenikova
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <iostream>

class WorkBaseTime {
 public:
  virtual unsigned int calcBase() = 0;
  virtual unsigned int calcBonus(unsigned nighttime, unsigned oversalary) = 0;
};

class ProjectBudget {
 public:
  virtual float calcBudgetPart(float part, int budget) = 0;
  virtual unsigned int calcProAdditions() = 0;
};

class Heading {
 public:
  virtual unsigned int calcHeads() = 0;
};

struct Project {
  unsigned id;
  unsigned budget;
};

#endif  // INCLUDE_INTERFACES_H_
