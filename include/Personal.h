// Copyright 2021 Bogomazov
#ifndef _INCLUDE_PERSONAL_H
#define _INCLUDE_PERSONAL_H


#include <iostream>
#include <string>
#include <vector>
#include "../include/Employee.h"
#include "../include/Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
    int salary = 0;
 public:
    Personal(int id,
             std::string name,
             std::string position,
             int worktime,
             int payment) :
                Employee(id, name, position, worktime, payment) {}
    void setSalary(int);
    int getSalary();
    int calcBase(int salary, int wtime);
    int calcBonus();
    int calc();
    void printInfo();
};

class Driver : public Personal {
 public:
    Driver(int id,
           std::string name,
           std::string position,
           int worktime,
           int payment) :
            Personal(id, name, position, worktime, payment) {}
    int calcBonus();
};

class Cleaner : public Personal {
 public:
    Cleaner(int id,
            std::string name,
            std::string position,
            int worktime,
            int  payment) :
                Personal(id, name, position, worktime, payment) {}
};

#endif //  _INCLUDE_PERSONAL_H
