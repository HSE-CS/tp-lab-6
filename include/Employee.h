// Copyright 2021 Galex

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum POS {
  CLEANER,
  DRIVER,
  PROGRAMMER,
  TESTER,
  TEAM_LEADER,
  PROJECT_MANAGER,
  SENIOR_MANAGER
};

class Employee {
 private:
  int id;
  std::string name;
  POS position;
  int workTime;
  double payment;
  double addPayment;

 public:
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  int getId();
  std::string getName();
  POS getPosition();
  int getWorkTime();
  double getPayment();
  double getAddPayment();
  void setId(int id);
  void setName(std::string name);
  void setPosition(POS position);
  void setWorkTime(int workTime);
  void setPayment(double payment);
  void setAddPayment(double bonus);
};

#endif  // INCLUDE_EMPLOYEE_H_
