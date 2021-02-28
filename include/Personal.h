// Copyright 2021 Schenikova
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Interfaces.h"
#include "Employee.h"

class Personal: public WorkBaseTime, public Employee {
 protected:
  unsigned int salary;
 public:
  unsigned int calcBase();
  void setSalary(unsigned int salary);
  unsigned int calcBonus(unsigned nighttime, unsigned oversalary);
};

class Driver : public Personal{
 private:
  unsigned nighttime;
  unsigned oversalary;
 public: 
  unsigned int calcBonus(unsigned nighttime, unsigned oversalary);
  void calc();
};

class Cleaner : public Personal {
 public:
  void calc();
};

#endif  // INCLUDE_PERSONAL_H_
