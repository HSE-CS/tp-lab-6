// Copyright 2021 Dev-will-work
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include "Employee.h"
#include "Interfaces.h"
class Personal : public Employee, WorkBaseTime {
 public:
  Personal();
  virtual ~Personal();
  virtual int calcBase(int salary, int wtime);
  virtual int calcBonus();

 protected:
  int salary = 0;

 private:
};

class Driver : public Personal {
 public:
  Driver(int salary, std::string fio, Position pos);
  virtual ~Driver();
  virtual void printInfo();
  // virtual int calcBase(int salary, int wtime);
  virtual int calcBonus();
  virtual void calc();

 private:
};

class Cleaner : public Personal {
 public:
  Cleaner(int salary, std::string fio, Position pos);
  virtual ~Cleaner();
  virtual void calc();
  // virtual int calcBase(int salary, int wtime);
  virtual void printInfo();


 private:
};

#endif  // INCLUDE_PERSONAL_H_
