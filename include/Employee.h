// Copyright 2021 Ryzhova Irina
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <iostream>

class Employee {
 protected:
  int id;
  std::string name;
  int payment = 0;
  int worktime = 0;
  std::string position;

 public:
  Employee(int payment, std::string name,
           std::string position, int id);
  void setWorktime(int);
  int getId();
  std::string getName();
  int getPayment();
  int getWorktime();
  std::string getPosition();
  virtual int calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
