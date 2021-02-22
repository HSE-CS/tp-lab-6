// Copyright 2021 LongaBonga
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <string>

class Employee {
 protected:
  std::string name;
  std::string position;
  int id;
  int worktime;
  int payment;

 public:
  Employee(int id, std::string name, std::string position, int payment,
           int worktime)
      : id(id),
        name(std::move(name)),
        position(std::move(position)),
        payment(payment),
        worktime(worktime) {}

  virtual int calc() = 0;
  virtual void printInfo() = 0;
  int getWorktime();
  int getPayment();
  int getId();
  std::string getName();
  std::string getPosition();
};

#endif  // INCLUDE_EMPLOYEE_H_
