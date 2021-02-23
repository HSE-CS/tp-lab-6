// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "fstream"

class Factory {
 public:
    std::vector<Employee*> makeStaff();
};


#endif  // INCLUDE_FACTORY_H_
