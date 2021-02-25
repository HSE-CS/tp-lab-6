// Copyright 2021 by Bodrov Egor
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
  int salaryPerHour{0};

 public:
  Personal(int id, int salaryPerHour, std::string name, std::string pos);
  int calcBase(int salaryPerHour, int worktime) override;
  int calcBonus() override;
  void calc() override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(int id, int salaryPerHour, std::string name);
  int calcBonus() override;
  void calc() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, int salaryPerHour, std::string name);
  int calcBonus() override;
  void calc() override;
};

#endif  // INCLUDE_PERSONAL_H_
