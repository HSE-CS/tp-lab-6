// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>

class Emploeey {
 public:
  Emploeey(int, std::string, std::string, int, int);
  ~Emploeey();

  int getId();
  std::string getName();
  std::string getPosition();
  int getWorktime();
  int getPayment();

  void setWorktime(int);
  virtual int calc() = 0;
  virtual void printInfo() = 0;

 private:
  int id;
  std::string name;
  std::string position;
  int worktime;
  int payment;
};

#endif  // INCLUDE_EMPLOYEE_H_
