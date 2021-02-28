// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <iostream>

class Employee {
 private:
  int id;
  std::string name;
  std::string position;
  double workTime;
  double payment;

 public:
  Employee(int id, std::string name, 
   std::string position, double payment);
  int getId();
  std::string getName();
  std::string getPosition();
  double getWorkTime();
  double getPayment();
  void updateWorkTime(double currentTime);
  virtual double calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
