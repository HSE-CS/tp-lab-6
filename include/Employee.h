// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum POSITIONS {
  DRIVER,
  CLEANER,
  PROJECT_MANAGER,
  TESTER,
  PROGRAMMER,
  TEAMLEADER,
  SENIORMANAGER,
  ENGINEER
};

class Employee {
 protected:
  size_t id;
  std::string name;
  POSITIONS position;
  unsigned int worktime;
  unsigned int payment;

 public:
  void setWorktime(unsigned int);
  virtual void printInfo() = 0;
  virtual void calc() = 0;
  int getId() const;
  std::string getName() const;
  POSITIONS getPosition() const;
  int getWorktime() const;
  int getPayment() const;
};

#endif  // INCLUDE_EMPLOYEE_H_
