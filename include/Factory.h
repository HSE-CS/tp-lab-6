// Copyright 2021 Schenikova
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Manager.h"
#include "Engineer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class StaffFactory {
 public:
  std::vector<Employee*> makeStaff(std::string filename);
};

#endif  // INCLUDE_FACTORY_H_
