// Copyright 2020 GHA Test Team
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_
#include <string>


struct Project {
  std::string id;
  int budget;
  int workers_num;
};


class WorkBaseTime {
public:
  virtual int calcBase(int salary, int wtime) const = 0;
  virtual int calcBonus() const = 0;
};


class ProjectBudget {
public:
  virtual int calcBudgetPart(float part, int budget) const = 0;
  virtual int calcProAdditions() const = 0;
};


class Heading {
  virtual int calcHeads() const = 0;
};
#endif  // INCLUDE_INTERFACES_H_
