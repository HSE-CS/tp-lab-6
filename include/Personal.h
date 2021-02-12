// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"

class Personal : public Employee, IWorkBaseTime {
 private:
  int salary;
 public:
  Personal(int salary);
  int calcBase(int salary, int wtime) override;
  int calcBonus() override;
};

class Driver : public Personal {
 public:
  Driver(int salary);
  int calcBase();
  int calc();
};

class Cleaner : public Personal {
 public:
  Cleaner(int salary);
  int calc();
};


#endif // INCLUDE_PERSONAL_H_
