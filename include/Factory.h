// Copyright 2021 Elise
#ifndef INCLUDE_FACTORYH
#define INCLUDE_FACTORYH

#include <string>
#include <utility>
#include <vector>

#include "Employee.h"

class Project {
 public:
  int id;
  std::string name;
  int budget;
  Project(int id, std::string name, int budget)
      : id(id), name(std::move(name)), budget(budget) {}
};

#endif  // INCLUDE_FACTORYH