// Copyright 2021 Lab_6 TiNa
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <iostream>
#include <string>

class Employee {
 protected:
  int id;
  int worktime;
  int payment;
  std::string name;
  std::string position;

 public:
  Employee(int id, std::string name, std::string position, int worktime,
           int payment);
  virtual int calc() = 0;
  virtual void printInfo() = 0;
  int getId();
  int getWorktime();
  int getPayment();
  std::string getName();
  std::string getPosition();
  void setId(int id);
  void setWorktime(int worktime);
  void setPayment(int payment);
  void setName(std::string name);
  void setPosition(std::string position);
};

#endif  // INCLUDE_EMPLOYEE_H_
