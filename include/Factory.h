//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <vector>
#include <string>
#include "external/json.hpp"
#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"

class Factory {
 public:
  using json = nlohmann::json;
  static std::vector<Employee *> makeStaff(const json &file);
};

#endif  //  INCLUDE_FACTORY_H_
