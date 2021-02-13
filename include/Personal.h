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

  int calc() override {
    return 0;
  }

  int calcBase(int p, int w) override {
    this->setSalary(p * w);
    return this->getSalary();
  }

  int calcBonus() override {
    return 0;
  }

  void printInfo() override {
    std::cout << "Personal{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", salary" + std::to_string(getSalary()) + "}" << std::endl;
  }

};

class Driver : public Personal {
 public:
  Driver(int id,
         const std::string &name,
         const std::string &position,
         int payment)
      : Personal(id,
                 name,
                 position,
                 payment) {}

  int calc() override {
    return getPayment() * getWorktime();
  }

  int calcBase(int p, int w) override {
    return Personal::calcBase(p, w);
  }

  int calcBonus() override {
    return getWorktime() > 40
           ? (getWorktime() - 40) * (int) (getPayment() * 1.5)
           : 0;
  }

  void printInfo() override {
    std::cout << "Driver{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", salary" + std::to_string(getSalary()) + "}" << std::endl;
  }

};

class Cleaner : public Personal {
 public:
  Cleaner(int id,
          const std::string &name,
          const std::string &position,
          int payment)
      : Personal(id,
                 name,
                 position,
                 payment) {}

  int calc() override {
    return getPayment() * getWorktime();
  }

  int calcBase(int p, int w) override {
    return Personal::calcBase(p, w);
  }

  int calcBonus() override {
    return Personal::calcBonus();
  }

  void printInfo() override {
    std::cout << "Cleaner{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", salary" + std::to_string(getSalary()) + "}" << std::endl;
  }
};

#endif  // INCLUDE_PERSONAL_H_
