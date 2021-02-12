// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_EMPLOYEE_H_
#define TP_LAB_6_SRC_EMPLOYEE_H_

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

#endif //TP_LAB_6_SRC_EMPLOYEE_H_
