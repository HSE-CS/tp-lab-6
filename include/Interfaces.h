// Copyright NikDemoShow 2021
#ifndef INERFACES_H_
#define INERFACES_H_
class WorkBaseTime {
 public:
  virtual unsigned int calcBase() = 0;
  virtual unsigned calcBonus() = 0;
};

class ProjectBudget {
  virtual unsigned int calcBudgetPart(const double part,
                                     const unsigned int budget) = 0;
  virtual unsigned int calcProAdditions() = 0;
};

class Heading {
  virtual unsigned int calcHeads() = 0;
};

#endif // INERFACES_H_
