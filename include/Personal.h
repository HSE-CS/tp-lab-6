// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
  int HourSalary{0};

 public:
  Personal(int id, int HourSalary, std::string name, std::string pos);
  int calcBase(int HourSalary, int worktime) override;
  int calcBonus() override;
  void calc() override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(int id, int HourSalary, std::string name);
  int calcBonus() override;
  void calc() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, int HourSalary, std::string name);
  int calcBonus() override;
  void calc() override;
};

#endif  // INCLUDE_PERSONAL_H_
