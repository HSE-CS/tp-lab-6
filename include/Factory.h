// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_


#include <vector>
#include "Employee.h"

class Factory {
 public:
    static std::vector <Employee*> makeStaff();
};


#endif  // INCLUDE_FACTORY_H_
