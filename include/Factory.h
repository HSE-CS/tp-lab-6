// Copyright 2021 by Bodrov Egor
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Interfaces.h"
#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Personal.h"
#include <fstream>
#include <vector>
#include <utility>
#include <string>

class FactoryWork {
 public:
  static std::vector<Employee*> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_
