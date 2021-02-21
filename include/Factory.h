// Copyright 2021 valvarl

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <utility>
#include <vector>
#include "Employee.h"
#include <string>

class Project {
 public:
    int is;
    std::string name;
    int budget;
    Project(int is, std::string name, int budget) :
    is(is), name(std::move(name)), budget(budget) {}
};

class StaffFactory {
 public:
    static std::vector<Employee*> makeStaff();
};


#endif  // INCLUDE_FACTORY_H_
