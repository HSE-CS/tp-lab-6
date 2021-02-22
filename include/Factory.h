// Copyright 2021 LongaBonga
#include "headers.h"

#ifndef FACTORY_H
#define FACTORY_H
class Project {
 public:
  int is;
  std::string name;
  int budget;
  Project(int is, std::string name, int budget)
      : is(is), name(std::move(name)), budget(budget) {}
};

#endif
