// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class Project {
 public:
  size_t id;
  unsigned int budget;
  explicit Project(size_t _id, unsigned int _budget) {
    id = _id;
    budget = _budget;
  }
};

class Heading {
 public:
  virtual unsigned int calcHeads() = 0;
};

class WorkBaseTime {
 public:
  virtual unsigned int calcBase() = 0;
  virtual unsigned int calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual unsigned int calcBudgetPart(double part, unsigned int budget) = 0;
  virtual unsigned int calcProAdditions() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
