// Copyright 2021 Pavlova D.

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public IWorkBaseTime {
 public:
  Personal(int id, std::string name, Position position, int _salary)
      : Employee(id, name, position, _salary) {}

  int calcBase(int _salary, int _wtime) override;
  void calc() override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, Position position, int _salary)
      : Personal(id, name, position, _salary) {}

  int calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, Position position, int _salary)
      : Personal(id, name, position, _salary) {}

  int calcBonus() override;
};
#endif  // INCLUDE_PERSONAL_H_
