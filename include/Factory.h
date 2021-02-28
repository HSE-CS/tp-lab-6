// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <sstream>
#include "Engineer.h"

class StaffFactory {
 public:
  StaffFactory();
  std::vector<Employee*> makeStaff(std::ifstream& employeesFile,
   std::ifstream& projectsFile);
};

#endif  // INCLUDE_FACTORY_H_
