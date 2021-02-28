// Copyright 2021 mkhorosh
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>

class Employee{  // basic(parent) class for all workers
 protected:
  std::string id;
  std::string name;
  std::string position;
  double work_time;
  double payment;

 public:
  void setWorkTime();
  void calc()=0;
  void printInfo()=0;
};

#endif  // INCLUDE_EMPLOYEE_H_
