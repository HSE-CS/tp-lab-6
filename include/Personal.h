// Copyright 2021 Tatsenko Alexey
#pragma once
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary_per_hour;

 public:
  Personal(int id, std::string fi, Position position, int salary_per_hour);
  int calc_base(int salary_per_hour, int wtime) override;
  int calc_bonus() override;
  void calc() override;
  void print_info() override;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string fi, Position position, int salary_per_hour);
  int calc_bonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string fi, Position position, int salary_per_hour);
  int calc_bonus() override;
};
