// Copyright [2021] <Roman Balayan>

#pragma once

#include <iostream>
#include <string>

#include "Interfaces.h"
#include "Employee.h"

class Personal :  public Employee,  public IWorkBaseTime {
 public:
    int calcBase(int salary, int wtime) override;
 protected:
    Personal(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary);
    unsigned int salary;
};

class Driver :  public Personal {
 public:
    Driver(unsigned int id,
        std::string name,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary);
    int calcBonus() override;
    void calc() override;
    void printInfo() override;
};

class Cleaner :  public Personal {
 public:
    Cleaner(unsigned int id,
        std::string name,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary);
    void calc() override;
    void printInfo() override;
};
