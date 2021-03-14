// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream> 
#include "Interfaces.h"


class Employee {
 protected:
    std::string ID;
    std::string name;
    std::string position;
    int worktime = 0;
    int payment = 0;

 public:
    Employee(std::string ID, std::string name, std::string position) {
        this->ID = ID;
        this->name = name;
        this->position = position;
    }
    std::string returnID();
    std::string returnPosition();
    int returnPayment();
    virtual void calc() = 0;
    virtual void printInfo();
    void addWorkTime(int time);
    void setToZero();
};

#endif   // INCLUDE_EMPLOYEE_H_
