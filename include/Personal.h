// Copyright 2021 mkhorosh
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include "Employee.h"

class Personal: public Employee{
 protected:
  double salary;

 public:
  void calcBase(); // ?
};

class Driver: public Personal{
 public:
  void calcBonus();
  void calc();
};

class Cleaner : public Personal{
 public:
  calc();
};

#endif  // INCLUDE_PERSONAL_H_
