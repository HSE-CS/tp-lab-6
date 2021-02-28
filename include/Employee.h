// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Position {
  DRIVER,
  TESTER,
  CLEANER,
  PERSONAL,
  TEAMLEADER,
  ENGINEER,
  PROJECTMANAGER,
  PROGRAMMER,
  SENIORMANAGER
};

class Employee {
 private:
  std::string id;
  std::string name;
  int worktime;
  double payment;
  Position position;
 public:
  Employee(std::string id, std::string name, int worktime, Position position);
  ~Employee();
  void setWorkTime();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  std::string getId();
  std::string getName();
  int getWorkTime();
  double getPayment();
  Position getPosition();
};

#endif  // INCLUDE_EMPLOYEE_H_
