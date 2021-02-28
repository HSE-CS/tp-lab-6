// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary;
 public:
  Personal(int id, std::string name,
           int workTime, int salary, Positions position);
  int calcBonus(int bonus = 0) override;
  void printInfo() override;
  int calcBase(int salaryValue, int workTimeValue) override;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name,
         int workTime, int salary, Positions position);
  int calc() override;
  int calcBonus(int bonus = 2) override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name,
          int workTime, int salary, Positions position);
  int calc() override;
};
#endif  // INCLUDE_PERSONAL_H_



