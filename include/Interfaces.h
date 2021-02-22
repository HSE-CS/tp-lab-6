#include "headers.h"

#ifndef INTERFACES_H
#define INTERFACES_H
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

#endif
