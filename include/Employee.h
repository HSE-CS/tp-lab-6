// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <iostream>
#include <string>
#include <vector>

class Employee {
 private:
    int id;
    std::string name;
    std::string pos;
    int worktime;
    int payment;

 public:
    Employee(int id, std::string name,
        std::string pos, int worktime, int payment);
    std::string getPosition();
    int getId();
    std::string getName();
    int getWorktime();
    int getPayment();
    void setWorkTime(int w);
    virtual int calc() = 0;
    virtual void printInfo() = 0;
};
#endif  // INCLUDE_EMPLOYEE_H_
