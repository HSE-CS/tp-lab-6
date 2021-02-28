// Copyright 2020 S. BOR
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Manager.h"
#include "Engineer.h"
#include <vector>
#include <string>

class Factory {
 public:
  std::vector<Employee *> fileRead(std::string fileName);
};

#endif  // INCLUDE_FACTORY_H_
