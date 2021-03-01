// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "string"
#include "Employee.h"

struct Project {
  int id;
  int budget;
};

std::vector<Employee*> readData(std::string file);
#endif  //  INCLUDE_FACTORY_H_
