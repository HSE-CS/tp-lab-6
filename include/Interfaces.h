#pragma once
#include <string>
#include <vector>

// This is the worst of the worst of OOP
class WorkBaseTime {
  virtual uint32_t calcBase(uint32_t salary, uint32_t wtime) = 0;
  virtual uint32_t calcBonus() = 0;
};

class ProjectBudget {
  virtual uint32_t calcBudgetPart(float part, uint32_t budget) = 0;
  virtual uint32_t calcProAdditions() = 0;
};

class Heading {
  virtual uint32_t calcHeads() = 0;
};

class Project {
 public:
  size_t id;
  uint32_t budget;
  uint32_t staff_num;
};
