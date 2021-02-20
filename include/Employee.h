// Copyright 2021 Arina Simonova

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Employee {
 private:
  int id;
  string name;
  string position;
  int workTime;
  int payment = 0;
 public:
  Employee(int _id, string _name, string _pos, int _workTime, int _payment);
  void SetWorkTime(int _workTime);
  void SetPayment(int _payment);
  int GetId();
  string GetName();
  string GetPosition();
  int GetWorkTime();
  int GetPayment();
  virtual int GetSalary() = 0;
  virtual int Calc() = 0;
  virtual void PrintInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
