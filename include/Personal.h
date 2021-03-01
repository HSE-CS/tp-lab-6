// Copyright 2021 Danyaev Artem
#pragma once

#include <iostream>
#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee, public WorkBaseTime {
 protected:
  int salary;
  int calcBase(int salary, int wtime);

 public:
  Personal(unsigned int id_, std::string& name_, Position pos, int salary_);
  void printInfo();
};


class Driver: public Personal {
 private:
  int calcBonus();

 public:
  Driver(unsigned int id_, std::string& name_, Position pos, int salary_);
  void calc();
};

class Cleaner: public Personal {
 private:
  int calcBonus();

 public:
  Cleaner(unsigned int id_, std::string& name_, Position pos, int salary_);
  void calc();
};
