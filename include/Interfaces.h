// Copyright 2021 LongaBonga
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <string>

class WorkBaseTime {
 public:
  virtual int calcBase(int salary, int wtime) = 0;
  virtual int calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

class Heading {
  virtual int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
