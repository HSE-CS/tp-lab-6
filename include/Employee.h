// Copyright 2020 S. BOR
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <iostream>

enum Position {DRIVER, CLEANER, PROGRAMMER, TESTER, TEAMLEADER,
PROJECTMANAGER, SENIORMANAGER};

class Factory;

class Employee {
 protected:
  unsigned id;
  std::string name;
  Position position;
  unsigned worktime;
  unsigned payment;

 public:
  unsigned getPayment();
  void setWorkTime(unsigned worktime);
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  friend Factory;
};

#endif  // INCLUDE_EMPLOYEE_H_
