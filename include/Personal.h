// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public IWorkBaseTime {
 public:
  Personal(std::string id,
    std::string name,
    double salary,
    Position position)
    : Employee(id, name, salary, position) {}
  int calcBase(int salary, int wtime) override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(std::string id,
    std::string name,
    double salary,
    Position position)
    : Personal(id, name, salary, position) {}
  int calcBonus() override;
  void calc() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(std::string id,
    std::string name,
    double salary,
    Position position)
    : Personal(id, name, salary, position) {}
  void calc() override;
  int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
