// Copyright 2021 Urtyukov Ilya
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <utility>
#include <vector>

#include "Employee.h"

class Project {
 public:
  int id;
  std::string name;
  int budget;
  Project(int, std::string, int)
};

#endif  // INCLUDE_FACTORY_H_
