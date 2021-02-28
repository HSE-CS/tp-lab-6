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
#include <random>

enum Position {
    unemployed = 0,
    cleaner,
    driver,
    manager,
    programmer,
    seniorManager,
    teamLeader,
    tester
};

class Employee {
 protected:
    unsigned id;
    std::string name;
    Position position;
    unsigned worktime;
    unsigned payment;
    std::string convertPositionToString();
 public:
    Employee(unsigned, const std::string&);
    void setWorkTime(unsigned);
    void setPosition(int);
    unsigned getPosition();
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};

#endif  //  INCLUDE_EMPLOYEE_H_
