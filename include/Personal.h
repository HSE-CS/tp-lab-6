// Copyright 2021 LongaBonga
#include <string>

#include "Employee.h"
#include "Interfaces.h"

#ifndef PERSONAL_H
#define PERSONAL_H

class Personal : public Employee, public WorkBaseTime {
 private:
  int salary = 0;

 public:
  Personal(int id, std::string name, std::string position, int payment,
           int worktime)
      : Employee(id, name, position, payment, worktime) {}

  int calc() override;
  int calcBase(int payment, int wtime) override;
  int calcBonus() override;
  void printInfo() override;
  int getSalary();
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, std::string position, int payment,
         int worktime)
      : Personal(id, name, position, payment, worktime) {}

  int calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, const std::string name, const std::string position,
          int payment, int worktime)
      : Personal(id, name, position, payment, worktime) {}
};
#endif
