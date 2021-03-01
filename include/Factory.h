#pragma once
// Copyright 2021 Tatsenko Ilya
#include <vector>
#include "Employee.h"

class Factory {
 private:
  std::vector<Employee*> staff;

 public:
  std::vector<Employee*> makeStaff(std::string file1, std::string file2);
};
