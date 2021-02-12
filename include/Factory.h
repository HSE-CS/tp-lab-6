// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include "Employee.h"

class Factory {
 public:
  static std::vector<Employee *> makeStaff(char * filepath);
};

#endif // INCLUDE_FACTORY_H_
