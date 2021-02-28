// Copyright 2021 kostinandrey

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
 public:
    Personal(int id, std::string name,
             int workTime, int salary, Positions position);
    int calc_bonus_salary(int bonus = 0) override;
    void print_info() override;
    int calc_base_salary(int salary, int work_time_salary)  override;
 protected:
    int salary;
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name,
           int work_time, int salary, Positions position);
    int calc_salary() override;
    int calc_bonus_salary(int bonus = 4) override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name,
            int work_time, int salary, Positions position);
    int calc_salary() override;
};
#endif  // INCLUDE_PERSONAL_H_
