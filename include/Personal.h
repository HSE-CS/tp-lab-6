// Copyright 2021 Lab_6 TiNa
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include "Employee.h"
#include "Interfaces.h"
#include <iostream>
#include <string>

class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary;

 public:
  Personal(int id, std::string name, std::string position, int salaryIn,
           int worktime, int payment)
      : Employee(id, name, position, worktime, payment), salary(salaryIn) {}
  int calcBase(int hour_salary, int work_time) override;
  int calc() override;
  float calcBonus() override;
  int getSalary();
  void setSalary(int salary);
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, std::string position, int salaryIn,
         int worktime, int payment)
      : Personal(id, name, position, salary, worktime, payment) {}
  int calc() override;
  float calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, std::string position, int salaryIn,
          int worktime, int payment)
      : Personal(id, name, position, salary, worktime, payment) {}
  int calc() override;
};

#endif  // INCLUDE_PERSONAL_H_
