// Copyright 2021 Smirnov Grigory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

enum position {
  Cleaner,
  Driver,
  Tester,
  Programmer,
  TeamLeader,
  ProjectManager,
  SeniorManager
};

class Employee {
 private:
  int id;
  int worktime=0;
  int payment = 0;
  position pos;
  std::string name;

 public:
  void setWorkTime(int numbOfHours);
  void setPayment(int money);
  int getWorkTime();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif 
