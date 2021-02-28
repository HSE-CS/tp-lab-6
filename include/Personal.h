// Copyright 27.02.21 DenisKabanov

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
  int salary = 0;

 public:
  explicit Personal(int id, std::string name, int salary) : Employee(id, name) {
    this->salary = salary;
  }
  int getSalary();
  virtual int calcBase(int salary, int worktime);
  virtual int calcBonus(int bonusCount, int bonusPrice);
  virtual void printInfo();
};

class Cleaner : public Personal {
 private:
  int passivesalary = 20000;
 public:
  Cleaner(int id, std::string name, int salary) : Personal(id, name, salary) {
    this->position = cleaner;
  }
  virtual void calc();
};

class Driver : public Personal {
 private:
  int passivesalary = 45000;
  int bonuses = 0;
 public:
  Driver(int id, std::string name, int salary) : Personal(id, name, salary) {
    this->position = driver;
  }
  void addBonus(int count);
  int getBonus();
  virtual int calcBonus(int bonusCount, int bonusPrice);
  virtual void calc();
};

#endif  // INCLUDE_PERSONAL_H_
