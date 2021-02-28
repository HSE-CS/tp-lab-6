// Copyright 2021 Galex

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "../include/Employee.h"
#include "../include/Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
  double salary;

 public:
  double calcBase(double salary, int workTime) override;
  void printInfo() override;
  void setSalary(double salary);
  double getSalary();
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, double salary);
  void calc() override;
  double calcBonus() override;
};

class Driver : public Personal {
 private:
  int numOfNightShifts;

 public:
  Driver(int id, std::string name, double salary);
  void calc() override;
  double calcBonus() override;
  void setNumOfNightShifts(int num);
  int getNumOfNightShifts();
};
#endif  // INCLUDE_PERSONAL_H_
