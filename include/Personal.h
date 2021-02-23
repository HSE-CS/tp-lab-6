// Copyright 2021 Smirnov Grigory
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
  int salary;

 public:
  int getSalary();
  virtual int calcBase(int salary, int wtime);
};

class Cleaner : public Personal {
 private:
  virtual void calc();
};

class Driver : public Personal {
 private:
  virtual int calcBonus();
  virtual void calc();
};
