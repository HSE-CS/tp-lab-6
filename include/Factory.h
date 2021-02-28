// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

class StaffFactory {
 public:
    std::vector<Employee*> makeStaff(std::string _projectsFile,
                                     std::string _employeesFile);
};

#endif  //  INCLUDE_FACTORY_H_
