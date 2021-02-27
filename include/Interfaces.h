// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
  virtual int calcBase(int, int) = 0;
  virtual int calcBonus() = 0;
};

class Heading {
 public:
  virtual int calcHeads() = 0;
};

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float, int) = 0;
  virtual int calcProAdditions() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
