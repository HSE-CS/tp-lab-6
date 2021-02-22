// Copyright 2021 LongaBonga
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "headers.h"

class Project {
 public:
  int is;
  std::string name;
  int budget;
  Project(int is, std::string name, int budget)
      : is(is), name(std::move(name)), budget(budget) {}
};

#endif  // INCLUDE_FACTORY_H_
