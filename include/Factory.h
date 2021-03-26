// Copyright 2021 by Liza
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include <locale>
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>
#include "Employee.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"

std::vector<Employee*> makeStaff(std::string staffList,
std::string projectsList);
#endif  // INCLUDE_FACTORY_H_
