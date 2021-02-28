// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
  int salary;

 public:
  Personal(int payment, std::string name,
           std::string position, int id, int salary);
  int getSalary();
  void setSalary(int);
  int calc();
  void printInfo();
  int calcBase(int salary, int wtime);
};

class Driver : public Personal {
 public:
  Driver(int payment, std::string name,
         std::string position, int id, int salary);
  int calc() override;
  int calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int payment, std::string name,
          std::string position, int id, int salary);
};

#endif  // INCLUDE_PERSONAL_H_
