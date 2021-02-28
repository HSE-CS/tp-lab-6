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
  void calc() override;
  int calcBase(int payment, int wtime) override;
  int calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, int salary)
    : Personal(id, name, salary) {
    setPosition(cleaner);
  }
  void calc() override;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, int salary)
    : Personal(id, name, salary) {
    setPosition(driver);
  }
  int calcBonus() override;
  void calc() override;
};

#endif  // INCLUDE_PERSONAL_H_
