// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"

class Personal : public Employee, IWorkBaseTime {
 private:
  int salary = 0;

 public:
  Personal(int id,
           const std::string &name,
           const std::string &position,
           int payment)
      : Employee(id,
                 name,
                 position,
                 payment) {}

  int getSalary() {
    return salary;
  }

  void setSalary(int s) {
    Personal::salary = s;
  }

  int calcBase(int p, int w) override {
    this->setSalary(p * w);
    return this->getSalary();
  }

  int calc() override {
    return 0;
  }

  void printInfo() override {
  }

  int calcBonus() override {
    return 0;
  }
};

class Driver : public Personal {
 public:
  int calcBase(int p, int w) override {
    return Personal::calcBase(p, w);
  }

  void printInfo() override {
    Personal::printInfo();
  }

  int calc() override {
    return getPayment() * getWorktime();
  }

  int calcBonus() override {
    return 500;
  }
};

class Cleaner : public Personal {
 public:
  int calcBase(int p, int w) override {
    return Personal::calcBase(p, w);
  }

  void printInfo() override {
    Personal::printInfo();
  }

  int calcBonus() override {
    return Personal::calcBonus();
  }

  int calc() override {
    return getPayment() * getWorktime();
  }
};

#endif  // INCLUDE_PERSONAL_H_
