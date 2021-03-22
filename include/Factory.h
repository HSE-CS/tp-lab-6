//
//  Factory.hpp
//  tp-lab-6
//
//  Created by Anastasiya Rogozyan on 15.03.2021.
//  Copyright © 2021 Anastasiya Rogozyan. All rights reserved.
//

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

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

#endif  // INCLUDE_FACTORY_H_
