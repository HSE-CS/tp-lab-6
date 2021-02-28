// Copyright 2021 me

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>

enum class Position {
  ENGINEER,
  PROGRAMMER,
  TESTER,
  TEAMLEADER,
  PROJECT_MANAGER,
  SENIOR_MANAGER,
  DRIVER,
  CLEANER
};

class Employee {
 private:
  unsigned id;
  std::string name;
  Position position;
  int worktime;
  int payment;

 protected:
  void setPayment(int pay);
 public:
  Employee(unsigned id, std::string name, Position position):
        id(id), name(name), position(position), payment(0), worktime(0) {};

  void setWorkTime(int workTime);
  int getWorkTime();
  int getPayment();
  std::string getPosition();
  std::string getName();
  unsigned getId();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
