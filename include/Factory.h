// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include <vector>
#include <string>

class StaffFactory {
 public:
  static std::vector<Employee*> make_staff(const std::string& file);
};

#endif  // INCLUDE_FACTORY_H_
