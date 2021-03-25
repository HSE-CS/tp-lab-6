// Copyright 2021 dash
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>

#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public WorkBaseTime {
 public:
    int calcBase(int salary, int worktime) override;
 protected:
    Personal(int id,
        std::string name,
        Position position,
        int worktime,
        int payment,
        int salary);

    int salary;
};

class Driver : public Personal {
 public:
    Driver(int id,
        std::string name,
        Position position,
        int worktime,
        int payment,
        int salary);
    int calcBonus() override;
    void calc();
    void print_Info();
};

class Cleaner : public Personal {
 public:
    Cleaner(int id,
        std::string name,
        Position position,
        int worktime,
        int payment,
        int salary);
    void calc();
    void print_Info();
    int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
