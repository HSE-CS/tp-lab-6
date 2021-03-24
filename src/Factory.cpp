// Copyright 2020 Ilya Urtyukov
#include "Interfaces.h"

#include "Employee.h"
#include "Factory.h"
#include <iostream>
#include <cstdlib>
#include <string>

Project::Project(int a, std::string s, int x) {
  id = a;
  name = s;
  budget = x;
}

