// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_FACTORY_H_
#define TP_LAB_6_SRC_FACTORY_H_

class Project {
 private:
  int id;
  int budget;
 public:
  int GetId() const {
    return id;
  }
  void SetId(int id) {
    Project::id = id;
  }
  int GetBudget() const {
    return budget;
  }
  void SetBudget(int budget) {
    Project::budget = budget;
  }
};

#endif //TP_LAB_6_SRC_FACTORY_H_
