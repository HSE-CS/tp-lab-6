//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_CLEANER_H_
#define INCLUDE_CLEANER_H_

#include "Personal.h"
#include <string>
#include <cstring>

class Cleaner : public Personal {
 public:
  int c_square{0};
  Cleaner(int id, std::string name, std::string position,
          int salary, int square);
  int calcBonus() override;
  void calc() override;
  void printinfo() override;
};

#endif  // INCLUDE_CLEANER_H_

