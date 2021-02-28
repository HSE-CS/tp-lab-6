// Copyright 2020 S. BOR
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Interfaces.h"
#include "Employee.h"

class Personal: public WorkBaseTime, public Employee {
 private:
  unsigned salary;

 public:
  void printInfo();
  void setSalary(unsigned salary);
  unsigned calcBase();
};

class Cleaner: public Personal {
 public:
  void calc();
  unsigned calcBonus(unsigned overtimeJob, unsigned cost);
};

class Driver: public Personal {
 public:
  unsigned calcBonus(unsigned overtimeJob, unsigned cost);
  void calc();
};

#endif  // INCLUDE_PERSONAL_H_
