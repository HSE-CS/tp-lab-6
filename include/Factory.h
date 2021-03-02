// Copyright 2021 Shirokov Alexander
#pragma once

#include <fstream>
#include <vector>
#include <utility>
#include <string>

#include "Employee.h"
#include "Manager.h"
#include "Engineer.h"
#include "Personal.h"
#include "Interfaces.h"

class FactoryWork {
 public:
  static std::vector<Employee*> makeStaff();
};
