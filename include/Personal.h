// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
  double salary;
 public:
  Personal(unsigned int id, std::string name,
    int worktime, double salary, int position);
  void calc();
  void printInfo();
  int calcBase();
  int calcBonus(int bonus = 0);
};

class Driver : public Personal {
 protected:
  int bonus;
 public:
  Driver(unsigned int id, std::string name,
    int worktime, double salary, int position);
  void calc();
};

class Cleaner : public Personal {
 public:
  Cleaner(unsigned int id, std::string name,
    int worktime, double salary, int position);
};
#endif  // INCLUDE_PERSONAL_H_



