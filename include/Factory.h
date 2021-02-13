// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Manager.h"

class Factory {
 public:
  static std::vector<Employee *> makeStaff(char *staffpath, char * projectspath);
};

#endif  // INCLUDE_FACTORY_H_
