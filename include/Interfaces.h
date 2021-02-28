// Copyright 27.02.21 DenisKabanov

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

struct WorkBaseTime {
  virtual int calcBase(int salary, int worktime) = 0;
  virtual int calcBonus(int bonusCount, int bonusPrice) = 0;
};

struct ProjectBudget {
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions(int addCount, int addPrice) = 0;
};

struct Heading {
  virtual int calcHeads(int salaryForSub) = 0;
};

#endif  // INCLUDE_INTERFACES_H_
