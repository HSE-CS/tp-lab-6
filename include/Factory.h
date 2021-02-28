// Copyright 2021 Islam Osmanov

#ifndef TP_LAB_6_FACTORY_H
#define TP_LAB_6_FACTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Personal.h"

class Factory {
 public:
    std::vector<Employee*> create_staff(std::string name);
};

#endif //TP_LAB_6_FACTORY_H
