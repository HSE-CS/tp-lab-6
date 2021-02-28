// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Engineer.h"
#include "Manager.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <fstream>

class StaffFactory {
 public:
  static std::vector<Employee*> makeStaff(std::string input);
};

#endif  // INCLUDE_FACTORY_H_