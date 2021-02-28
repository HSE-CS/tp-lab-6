// Copyright 2021 Sozinov Kirill

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <iostream>

class Employee {
protected:
    int id;
    std::string name;
    std::string position;
    int worktime;
    double payment;
 public:
     Employee(int, std::string, std::string);
     void setWorkTime(int wt);
     virtual void calc() = 0;
     virtual void printInfo() = 0;
     std::string getName();
     int getId();
     std::string getPosition();
     int getWorktime();
     int getPayment()
};

#endif  // INCLUDE_EMPLOYEE_H_
