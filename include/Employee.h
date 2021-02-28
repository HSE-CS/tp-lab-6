//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

enum Position {
    Unemployed = 0,
    Cleaner,
    Driver,
    Engineer,
    Manager,
    Programmer,
    SeniorManager,
    TeamLeader,
    Tester
};

class Employee {
 protected:
    unsigned id;
    std::string name;
    Position position;
    unsigned worktime;
    unsigned payment;
 public:
    Employee(unsigned, std::string);
    ~Employee();
    void setWorkTime(unsigned);
    void setPosition(int);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};

#endif  //  INCLUDE_EMPLOYEE_H_
