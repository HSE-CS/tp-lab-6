// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"

class StaffFactory {
 public:
  static std::vector<Employee*> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_