// Copyright 2021 Ksuvot
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>
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
  void setSalary(int salary);
  virtual int calcBase(int salary, int worktime);;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, int salary)
    : Personal(id, name, salary) {
    setPosition(cleaner);
  }
  virtual void calc();
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, int salary)
    : Personal(id, name, salary) {
    setPosition(driver);
  }
  virtual int calcBonus();
  virtual void calc();
};

#endif  // INCLUDE_PERSONAL_H_
