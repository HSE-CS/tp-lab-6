// Copyright 2021 GN
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "Manager.h"
#include "Engineer.h"
#include "Personal.h"

class Factory {
 private:
     std::vector<Employee*>factory_employees;

 public:
     void createStaff();
};

#endif  // INCLUDE_FACTORY_H_
