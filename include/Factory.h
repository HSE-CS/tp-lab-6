// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include <map>
#include "Personal.h"

class StaffFactory {
 public:
  static std::vector<Employee *> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_



