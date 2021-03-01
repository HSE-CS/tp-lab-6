// Copyright 2021 Danyaev Artem
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

class Factory {
 public:
  static std::vector <Employee*> makeStaff(std::string projectsPath,
	  std::string staffPath);
};
