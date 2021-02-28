// Copyright 2021 Lab_6 TiNa
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_
#include <iostream>
#include <string>

class WorkBaseTime {
 public:
  virtual int calcBase(int hour_salary, int work_time) = 0;
  virtual int calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float contrib, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

class Heading {
  virtual int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
