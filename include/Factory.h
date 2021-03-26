// Copyright 2020 Uskova
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Employee.h"
#include "Project.h"


std::vector<Employee*> readWorkers(std::string file, Project* proj);
Employee* apdate(Employee* worker, Project* proj);

#endif  // INCLUDE_FACTORY_H_
