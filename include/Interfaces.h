// Copyright 2021 Elise
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
  virtual size_t calcBase(size_t salary, size_t wtime) = 0;
  virtual size_t calcBonus() = 0;
};

class Heading {
  virtual size_t calcHeads() = 0;
};

class ProjectBudget {
  virtual size_t calcBudgetPart(float part, int budget) = 0;
  virtual size_t calcProAdditions() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
