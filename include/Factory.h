// Copyright 2021 Islam Osmanov

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Personal.h"

class Factory {
 public:
    std::vector<Employee*> create_staff(std::string name);
};

#endif  // INCLUDE_FACTORY_H_H
