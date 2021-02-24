// Copyright 2021 LongaBonga
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public WorkBaseTime {
 private:
  int salary = 0;

 public:
  Personal(int id, std::string name, std::string position, int salary,
           int worktime)
      : Employee(id, name, position, 0, worktime), salary(salary) {}

  int calc() override;
  int calcBase(int payment, int wtime) override;
  int calcBonus() override;
  void printInfo() override;
  int getSalary();
  void setSalary(int value);
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

#endif  // INCLUDE_PERSONAL_H_
