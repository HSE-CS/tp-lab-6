// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>

#include "Manager.h"
#include "Personal.h"

class Factory {
 public:
  static std::vector<Employee*> makeStaff(const char* filename);
};

#endif  // INCLUDE_FACTORY_H_
