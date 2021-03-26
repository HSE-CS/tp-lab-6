// Copyright 2021 by mila
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <fstream>
#include <vector>
#include <iostream>
#include <string>


#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"

class StaffFactory {
 public:
    std::vector<Employee * > makeStaff();
}


#endif // INCLUDE_FACTORY_H_
