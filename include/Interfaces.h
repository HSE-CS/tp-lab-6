// Copyright 2020 me

#ifndef INCLUDE_INTERFACES_H
#define INCLUDE_INTERFACES_H

class WorkBaseTime {
 public:
  virtual int calcBase(int salary, int wtime) = 0;
  virtual int calcBonus() = 0;
};

class Heading {
 public:
  virtual int calcHeads() = 0;
};

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

#endif  // INCLUDE_INTERFACES_H
