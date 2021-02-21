//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

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
  virtual int calcBudgetPart(double part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

#endif  //  INCLUDE_INTERFACES_H_
