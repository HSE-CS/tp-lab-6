//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_DRIVER_H_
#define INCLUDE_DRIVER_H_

#include "Personal.h"
#include <string>
#include <cstring>

class Driver : public Personal {
 public:
  int kilometers{0};
  Driver(int id, std::string name, std::string position,
         int salary, int km);
  int calcBonus() override;
  void calc() override;
  void printinfo() override;
};

#endif  // INCLUDE_DRIVER_H_

