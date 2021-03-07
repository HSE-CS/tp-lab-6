// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Position {
  DRIVER,
  TESTER,
  CLEANER,
  TEAMLEADER,
  PROJECTMANAGER,
  PROGRAMMER,
  SENIORMANAGER
};

class Employee {
 private:
  std::string id;
  std::string name;
  Position position;
 protected:
  int worktime;
  double payment = 0;
  double salary;
 public:
  Employee(std::string id, std::string name, double salary, Position position) {
    this->id = id;
    this->name = name;
    this->salary = salary;
    this->position = position;
  }
  void setWorkTime(int wtime);
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  Position getPosition();
  std::string getId();
  std::string getName();
};

#endif  // INCLUDE_EMPLOYEE_H_
