// Copyright 2021 Pavlova D.

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include "Interfaces.h"
#include <iostream>
#include <string>
#include <utility>

enum Position {
  PROJECT_MANAGER,
  SENIOR_MANAGER,
  TEAM_LEADER,
  PROGRAMMER,
  CLEANER,
  TESTER,
  DRIVER
};

class Employee {
 private:
  int id;
  std::string name;
  Position position;

 public:
  int payment = 0;
  int salary = 0;
  int worktime = 0;

  Employee(int id, const std::string &name, Position position, int salary)
      : id(id), name(name), position(position), salary(salary) {}

  [[nodiscard]] int getId() const;
  std::string getName();
  Position getPosition();

  void setWorkTime(int wTime);

  virtual void calc();
  virtual void printInfo();
};

#endif  // INCLUDE_EMPLOYEE_H_
