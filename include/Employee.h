// Copyright 2021 Arina Simonova

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#pragma once

#include <string>
#include <iostream>


class Employee {
 private:
  int id;
  std::string name;
  std::string position;
  int workTime;
  int payment = 0;
 public:
  Employee(int _id, std::string _name, std::string _pos,
    int _workTime, int _payment);
  void SetWorkTime(int _workTime);
  void SetPayment(int _payment);
  int GetId();
  std::string GetName();
  std::string GetPosition();
  int GetWorkTime();
  int GetPayment();
  virtual int GetSalary() = 0;
  virtual int Calc() = 0;
  virtual void PrintInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
