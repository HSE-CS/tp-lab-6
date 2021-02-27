// Copyright 2021 Elise
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>
#include <iostream>
#include <utility>

#include "Interfaces.h"

class Employee {
 private:
  int id;
  std::string name;
  int worktime;
  std::string position;

 public:
  Employee(int id, std::string name, std::string position, int payment,
           int worktime)
      : id(id),
        name(std::move(name)),
        position(std::move(position)),
        payment(payment),
        worktime(worktime) {}
  int payment;
  void set_id(int);
  void set_name(std::string&);
  void set_worktime(int);
  void set_position(std::string&);
  void set_payment(int);
  int get_id();
  std::string& get_name();
  int get_worktime();
  std::string get_position();
  int get_payment();
  int virtual calc() = 0;
  void virtual printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
