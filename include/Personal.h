// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
    int salary;
 public:
    Personal(int id, std::string name, Position position, int salary);
    int calcBase(int salary, int wtime);
    int calcBonus();
    void printInfo();
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name, Position position, int salary);
    void calc();
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name, Position position, int salary);
    void calc();
};

#endif  // INCLUDE_PERSONAL_H_
