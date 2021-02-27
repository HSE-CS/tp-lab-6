// Copyright 2021 Ksuvot
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <utility>
#include <iostream>

enum Position {
  cleaner,
  driver,
  tester,
  programmer,
  teamleader,
  projectmanager,
  seniormanager
};

class Employee {
 private:
  int id;
  int payment = 0;
  int worktime = 0;
  std::string name;
  Position position;

 public:
  Employee(int id, std::string name) {
    this->id = id;
    this->name = std::move(name);
  }
  int getId();
  int getPayment();
  int getWorktime();
  Position getPosition();
  std::string getName();

  void setId(int id);
  void setPayment(int payment);
  void setWorkTime(int worktime);
  void setName(std::string name);
  void setPosition(Position position);

  virtual void calc() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
