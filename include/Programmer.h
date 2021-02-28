//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_PROGRAMMER_H_
#define INCLUDE_PROGRAMMER_H_

#include "Engineer.h"
#include <string>
#include <cstring>

class Programmer : public Engineer {
 public:
  bool Deadline;
  Programmer(int id, std::string name, std::string position,
             int salary, Project* project, float part);
  void calc() override;
  void printinfo() override;
  int calcProAdditions() override;
};

#endif  // INCLUDE_PROGRAMMER_H_

