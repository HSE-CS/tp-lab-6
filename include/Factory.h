// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_FACTORY_H_
#define TP_LAB_6_SRC_FACTORY_H_

#include <string>
#include <vector>
#include "Employee.h"

class Factory {
 public:
  static std::vector<Employee *> makeStaff(char * filepath);
};

#endif //TP_LAB_6_SRC_FACTORY_H_
