// Copyright 2021 Galex

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
  virtual double calcBase(double salary, int workTime) = 0;
  virtual double calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual double calcBudgetPart(double part, int budget) = 0;
  virtual void calcProAdditions() = 0;
};

class Heading {
 public:
  virtual double calcHeads() = 0;
};
#endif  // INCLUDE_INTERFACES_H_
