// Copyright 2021 Bogomazov
#ifndef _INCLUDE_FACTORY_H
#define _INCLUDE_FACTORY_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "../include/Employee.h"


class Project {
 public:
    int id;
    int budget;
    std::string name;
    Project(int id, std::string name, int budget)
        : id(id), name(std::move(name)), budget(budget) {}
};

class Factory {
 private:
    std::vector<Employee*> staff;
 public:
    std::vector<Employee*> makeStaff(const std::string dir);
};


#endif //  _INCLUDE_FACTORY_H
