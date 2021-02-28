// Copyright 2021 Schenikova
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>

enum Position {ENGINEER, CLEANER, DRIVER, PROGRAMMER, TESTER, TEAMLEADER,
PROJECTMANAGER, SENIORMANAGER};

class StaffFactory;

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
  void setId(int id);
  void setName(std::string name);
  void setPosition(Position position);
  friend StaffFactory;
};

#endif  // INCLUDE_EMPLOYEE_H_
