// Copyright 2021 kostinandrey
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <vector>
#include <map>
#include "Personal.h"

class Factory_Staff {
public:
    static std::vector<Employee *> make_staff();
};

#endif  // INCLUDE_FACTORY_H_
