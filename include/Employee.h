// Copyright 2021 Schenikova
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>

enum Position {ENGINEER, CLEANER, DRIVR, PROGRAMMER, TESTER, TEAMLEADER,
PROJECTMANAGER, SENIORMANAGER};

class Employee {
 protected:
  unsigned int id;
  std::string name;
  Position position;
  unsigned int worktime;
  unsigned int payment;
 public:
  // Employee();
  void setWorkTime(unsigned int worktime);
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  int getPayment();
  // ~Employee();
};

#endif  // INCLUDE_EMPLOYEE_H_
