// Copyright 2021 Arina Simonova

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#pragma once

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, IWorkBaseTime {
 private:
  int salary;
 public:
  Personal(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary);
  void SetSalary(int salary);
  int calcBase(int salary, int wtime);
  int calcBonus();
  int GetSalary();
  void PrintInfo();
  int Calc();
};

class Driver : public Personal  {
 public:
  Driver(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary);
  int calcBonus();
};

class Cleaner : public Personal {
 public:
  Cleaner(int _id, std::string _name, std::string _pos, int _workTime,
    int _payment, int _salary);
};

#endif  // INCLUDE_PERSONAL_H_
