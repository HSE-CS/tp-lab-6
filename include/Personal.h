// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include "string"

class Personal : public Employee, WorkBaseTime {
 public:
  explicit Personal(int id, std::string name, std::string position,
    int workTime, int payment)
    : Employee(id, name, position, workTime, payment) {}
  void setSalary(int salary);
  int getSalary();
  int calc() override;
  void printInfo() override;
  int calcBonus() override;
  int calcBase(int salary, int worktime) override;
 private:
  int salary;
};

class Driver : public Personal {
 public:
  explicit Driver(int id, std::string name, std::string position,
    int workTime, int payment)
    : Personal(id, name, position, workTime, payment) {}
  int calc();
  int calcBase(int salary, int worktime) override;
  void printInfo() override;
};

class Cleaner : public Personal {
 public:
  explicit Cleaner(int id, std::string name, std::string position,
    int workTime, int payment)
    : Personal(id, name, position, workTime, payment) {}
  int calc();
  int calcBase(int salary, int worktime) override;
  void printInfo() override;
};
#endif  //  INCLUDE_PERSONAL_H_
