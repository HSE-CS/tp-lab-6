// Copyright 2021 Pavlova D.

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

class StaffFactory {
 public:
  static std::vector<Employee *> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_
