// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <cstdint>
#include <string>

class WorkBaseTime {
 protected:
  virtual uint32_t calcBase(uint32_t salary, uint32_t worktime) = 0;
  virtual uint32_t calcBonus() = 0;
};

class ProjectBudget {
 protected:
  virtual uint32_t calcBudgetPart(double part, uint32_t budget) = 0;
  virtual uint32_t calcProAdditions() = 0;
};

class Heading {
 protected:
  virtual uint32_t calcHeads() = 0;
};

struct project_t {
  std::string name;
  uint64_t budget;
  uint32_t staff_size;
};

#endif  // INCLUDE_INTERFACES_H_
