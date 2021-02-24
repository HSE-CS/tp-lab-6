// Copyright 2021 Dev-will-work
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <iostream>
#include <string>

enum class Position {
  PROJECT_MANAGER, SENIOR_MANAGER, PROGRAMMER, TESTER, TEAMLEADER,
  DRIVER, CLEANER
};

struct Project {
  uint64_t id;
  int budget;
};

class Employee {
 public:
  Employee();
  virtual ~Employee();
  virtual Position getPosition();
  virtual int getPayment();
  virtual void setWorkTime(int);
  virtual void setSubordCount(size_t);
  virtual uint64_t createId();
  virtual void calc() = 0;
  virtual void printInfo() = 0;


 protected:
  uint64_t id = 0;
  std::string name;
  Position position;
  int worktime = 0;
  int payment = 0;
  size_t subordinates_count = 0;

 private:
};
#endif  // INCLUDE_EMPLOYEE_H_
