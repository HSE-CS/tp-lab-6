// Copyright 2021 Smirnov Grigory
#ifndef PERSONAL_H
#define PERSONAL_H

#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
  int salary;

 public:
   Personal(int id, std::string name, int salary) : Employee(id, name) {
     this->salary = salary;
   }
  int getSalary();
  virtual int calcBase(int salary, int wtime);
  virtual int calcBonus();
  virtual void printInfo();
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, int salary) : Personal(id, name, salary) {};
  virtual void calc();
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, int salary) : Personal(id, name, salary) {};
  virtual int calcBonus();
  virtual void calc();
};

#endif
