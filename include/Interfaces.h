// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_INCLUDE_INTERFACES_H_
#define TP_LAB_6_INCLUDE_INTERFACES_H_

class IHeading {
 public:
  virtual int calcHeads() = 0;
};

class IProjectBudget {
 public:
  int calcBudgetPart(float part, int budget) = 0;
  int calcProAdditions() = 0;
};

class IWorkBaseTime {
 public:
  int calcBase(int salary, int wtime) = 0;
  int calcBonus() = 0;
};

#endif //TP_LAB_6_INCLUDE_INTERFACES_H_
