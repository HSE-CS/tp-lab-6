// Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_TESTER_H_
#define INCLUDE_TESTER_H_

#include "Engineer.h"

class Tester : public Engineer {
 public:
  Tester(int id, std::string name, std::string position,
         int salary, Project* project, float part);
  void calc() override;
  void printinfo() override;
  int calcProAdditions() override;
};

#endif  // INCLUDE_TESTER_H_

