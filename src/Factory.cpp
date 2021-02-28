// Copyright 2021 Egor Trukhin
#include "Factory.h"

std::vector<Employee*> Factory::makeStaff(const char* filename) {
  std::vector<Employee*> staff;

  staff.push_back(new Cleaner(1, std::string("Egor"), 100));
  staff.push_back(new Cleaner(2, std::string("Oleg"), 100));
  staff.push_back(new Driver(3, std::string("SDfasdf aSDF"), 500));
  staff.push_back(new Driver(4, std::string("Adfzxcv"), 600));

  return staff;
}
