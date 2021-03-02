// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
  virtual int calcBase(int salary, int wtime) = 0;
  virtual int calcBonus() = 0;
};

class ProjectBudget {
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

class Heading {
  virtual int calcHeads() = 0;
};

#endif  //  INCLUDE_INTERFACES_H_
