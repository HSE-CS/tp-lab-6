// Copyright 2021 Smirnov Grigory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

enum class position {
  Cleaner,
  Driver,
  Tester,
  Programmer,
  TeamLeader,
  ProjectManager,
  SeniorManager
};

class Employee {
 private:
  int id;
  int worktime=0;
  int payment = 0;
  position pos;
  std::string name;

 public:
  Employee(int id, std::string name);
  void setWorkTime(int numbOfHours);
  void setPayment(int money);
  int getWorkTime();
  std::string getName();
  int getId();
  int getPayment();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif 
