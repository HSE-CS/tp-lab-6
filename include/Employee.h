// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <cstdint>
#include <string>

enum position_t {
  CLEANER,
  DRIVER,
  TESTER,
  PROGRAMMER,
  TEAMLEADER,
  PROJECTMANAGER,
  SENIORMANAGER
};

class Employee {
 protected:
  uint32_t id;
  std::string name;
  position_t position;
  uint32_t worktime, payment;

  Employee(uint32_t id, std::string& name);
  void printId();

 public:
  void setWorkTime(uint32_t time);
  virtual void printInfo();
  virtual void calc() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
