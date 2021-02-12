// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

class Employee {
 private:
  int id;
  std::string name;
  std::string position;
  int worktime;
  int payment;
 public:
  void setWorkTime(int worktime);
  void calc();
  void printInfo();
};

#endif  // INCLUDE_EMPLOYEE_H_