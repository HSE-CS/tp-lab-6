// Copyright 2021 alexgiving

#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <cstdio>

class Project {
 private:
  size_t id = 0;
  size_t budget = 0;

 public:
  Project();
  Project(size_t, size_t);
  void setProjectId(size_t);
  void setBudget(size_t);
  [[nodiscard]] float calcBudgetPart(float) const;
  [[nodiscard]] size_t getProjectId() const;
  [[nodiscard]] size_t getBudget() const;
};

#endif  // INCLUDE_PROJECT_H_
