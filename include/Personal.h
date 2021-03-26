// Copyright 2020 Uskova
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>

#include "Employee.h"
#include "Interfaces.h"


class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary;

 public:
  Personal(int, std::string, Position, int, int);
  int calcBase(int, int) override;
};

class Driver : public Personal {
 private:
  int extraTime;

 public:
  Driver(int, std::string, Position, int, int, int);
  int calcBonus() override;
  void calc() override;
  void printinfo() override;
  int getExtraTime();
};

class Cleaner : public Personal {
 public:
  Cleaner(int, std::string, Position, int, int);
  void calc() override;
  void printinfo() override;
  int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
