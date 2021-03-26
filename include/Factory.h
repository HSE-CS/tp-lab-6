// Copyright 2021 Ziganshin Nikita

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include "Employee.h"
#include <fstream>
#include <string>
#include <vector>

class StaffFactory {
 public:
    static std::vector<Employee*> makeStaff(const std::string& path);
};

#endif  // INCLUDE_FACTORY_H_
