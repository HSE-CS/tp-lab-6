// Copyright 2021 LongaBonga
#include "headers.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
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

#endif
