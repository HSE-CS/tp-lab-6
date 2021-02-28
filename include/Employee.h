// Copyright DB 2021
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <iomanip>
#include <iostream>
#include <string>
enum Position {
  Senior_Manager,
  Project_Manager,
  Team_Leader,
  programmer,
  tester,
  driver,
  cleaner
};

class Employee {
 protected:
  int id;
  std::string name;
  Position position;
  int workTime;
  int payment;

 public:
  Employee(int id, std::string name, Position position)
      : id(id), name(std::move(name)), position(position), payment(0) {}
  void setWorkTime(int workTime);
  virtual void calc() = 0;
  virtual void printInfo();
  int getPayment() const;
  std::string getPosition() const;
};

#endif  // INCLUDE_EMPLOYEE_H_