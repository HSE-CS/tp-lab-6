// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>

#include "Employee.h"
#include "Interfaces.h"

class Employee;
class WorkBaseTime;

class Personal : public Employee, public WorkBaseTime {
 protected:
  unsigned int salary;

 public:
  unsigned int calcBase() override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(int _id, std::string _name, int _salary);
  unsigned int calcBonus() override;
  void calc() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int _id, std::string _name, int _salary);
  void calc() override;
  unsigned int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
