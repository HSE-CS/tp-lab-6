// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
  double salary;

 public:
  Personal(int id, std::string name, std::string position,
   double payment);
  virtual double calcBase();
  double getSalary();
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, std::string position,
   double payment);
  virtual double calcBonus();
  virtual double calc();
  virtual void printInfo();
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, std::string position,
   double payment);
  virtual double calc();
  virtual void printInfo();

 private:
  virtual double calcBonus();
};

#endif  // INCLUDE_PERSONAL_H_
