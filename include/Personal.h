// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include <iostream>
#include <cmath>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
    unsigned int salary;

 public:
    Personal(unsigned int _id, std::string _name,
             POSITION _position, unsigned int _salary);
    void calc() override;
    unsigned int calcBase(unsigned int _salary,
                          unsigned int _worktime) override;
    unsigned int calcBonus() override;
    void printInfo() override;
};

class Driver : public Personal {
 public:
    Driver(unsigned int _id, std::string _name,
          POSITION _position, unsigned int _salary);
    unsigned int calcBonus() override;
};

class Cleaner : public Personal {
 public:
    Cleaner(unsigned int _id, std::string _name,
          POSITION _position, unsigned int _salary);
};


#endif  //  INCLUDE_PERSONAL_H_
