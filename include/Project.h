//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <string>

class Project {
 public:
  int p_id;
  int p_budget;
  Project(int id, int budget) {
    p_id = id;
    p_budget = budget;
  }
};

#endif  // INCLUDE_PROJECT_H_

