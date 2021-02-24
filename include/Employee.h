// Copyright 2021 Smirnov Grigory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

enum position {
  CLEANER,
  DRIVER,
  TESTER,
  PROGRAMMER,
  TEAMLEADER,
  PROJECTMANAGER,
  SENIORMANAGER
};

class Employee {
 private:
  int id;
  int worktime = 0;
  int payment = 0;
  std::string name;

 protected:
  position pos;

 public:
  Employee(int id, std::string name);
  void setWorkTime(int numbOfHours);
  void setPayment(int money);
  int getWorkTime();
  std::string getName();
  int getId();
  int getPayment();
  position getPos();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif 
