// Copyright 2021 Ksuvot
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
  virtual int calcBonus() = 0;
  virtual int calcBase(int salary, int worktime) = 0;
};

class ProjectBudget {
 public:
  virtual int calcProAdditions() = 0;
  virtual int calcBudgetPart(float part, int budget) = 0;
};

class Heading {
 public:
  virtual int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
