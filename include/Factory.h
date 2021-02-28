// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include <string>
#include <vector>


class StaffFactory {
 public:
 static std::vector<Employee*> make_staff(const std::string& file);
};

#endif  // INCLUDE_FACTORY_H_
