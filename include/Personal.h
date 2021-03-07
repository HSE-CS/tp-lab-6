// Copyright 2021 Urtyukov Ilya
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include <vector>

#include "Interfaces.h"
#include "Employee.h"


class Personal : public WorkBaseTime, public Employee {
 private:
  int salary;

 public:
  Personal(int, std::string, std::string, int, int)
  void set_salary(int);
  int calcBase(int salary, int wtime);
  int get_salary();
};

class Driver : public Personal {
 public:
  Driver(int, std::string, std::string, int, int)
  int calcBonus();
  int calc();
  void printInfo();
};

class Cleaner : public Personal {
 public:
  Cleaner(int, std::string, std::string, int, int)
  int calc();
  void printInfo();
};

#endif  // INCLUDE_PERSONAL_H_
