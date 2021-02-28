// Copyright 2021 Bogomazov
#ifndef _INCLUDE_EMPLOYEE_H
#define _INCLUDE_EMPLOYEE_H

#include <vector>
#include <string>
#include "../include/Interfaces.h"


class Employee {
 protected:
    int id;
    std::string name;
    std::string position;
    int worktime;
    int payment;
 public:
    Employee(int id,
             std::string name,
             std::string position,
             int worktime, int payment);
    int getId();
    std::string getName();
    std::string getPosition();
    void setWorkTime(size_t wtime);
    int getWorkTime();
    int getPayment();
    virtual int calc() = 0;
    virtual void printInfo() = 0;
};

#endif  // INCLUDE_COMPANY_H_
