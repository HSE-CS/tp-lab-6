// Copyright 27.02.21 DenisKabanov

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"

class StaffFactory {
 private:
  std::vector<Employee*> staff;

 public:
  void makeStaff();
};

#endif  // INCLUDE_FACTORY_H_
