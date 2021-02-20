// Copyright 2021 Arina Simonova

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#pragma once

#include <vector>
#include "Employee.h"
#include <locale>
#include "Manager.h"
#include "Engineer.h"
#include <fstream>
#include <sstream>

vector<Employee *> makeStaff(char *staffList, char *projectsList);

#endif  // INCLUDE_FACTORY_H_
