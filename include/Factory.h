// Copyright 2021 Kris

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "Employee.h"
#include "Personal.h"
#include <locale>
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>

std::vector<Employee*> makeStaff(std::string staffList,
    std::string projectsList);

#endif  // INCLUDE_FACTORY_H_
