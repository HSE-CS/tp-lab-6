// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Engineer.h"
#include "Manager.h"

class StaffFactory {
 public:
  static std::vector<Employee*> makeStaff(std::string input);
};

#endif  // INCLUDE_FACTORY_H_
