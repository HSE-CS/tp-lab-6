// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include <string>
#include <vector>

class StaffFactory {
 public:
  static std::vector<Employee*> makeStaff(std::string file_name);
};

#endif  // INCLUDE_FACTORY_H_
