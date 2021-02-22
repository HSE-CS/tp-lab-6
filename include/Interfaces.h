// Copyright 2021 VadMack

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <string>
#include <utility>
class WorkBaseTime {
 public:
  virtual int calcBase(int salary, int workTime) = 0;
  virtual int calcBonus() = 0;
};

class ProjectBudget {
 public:
  virtual int calcBudgetPart(float part, int budget) = 0;
  virtual int calcProAdditions() = 0;
};

class Heading {
 public:
  virtual int calcHeads() = 0;
};

class Project {
 protected:
  std::string id;
  int budget;

 public:
  Project(std::string id, int budget) : id(std::move(id)), budget(budget) {}
  const std::string &GetId() const {
    return id;
  }
  void SetId(const std::string &id) {
    Project::id = id;
  }
  int GetBudget() const {
    return budget;
  }
  void SetBudget(int budget) {
    Project::budget = budget;
  }
};

#endif // INCLUDE_INTERFACES_H_