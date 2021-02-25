// Copyright NikDemoShow 2021
#ifndef SRC_INTERFACES_H_
#define SRC_INTERFACES_H_
class WorkBaseTime {
 public:
  virtual unsigned int calcBase() = 0;
  virtual unsigned calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual unsigned int calcBudgetPart(const double part,
                                     const unsigned int budget) = 0;
  virtual unsigned int calcProAdditions() = 0;
};

class Heading {
 public:
  virtual unsigned int calcHeads() = 0;
};

#endif  // SRC_INTEFACES_H_
