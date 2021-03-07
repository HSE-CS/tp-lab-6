// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"
#include "Interfaces.h"


class FactoryWork {
 public:
  static std::vector<Employee*> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_
