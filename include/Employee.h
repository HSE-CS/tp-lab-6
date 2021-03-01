// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>

struct Project {
    std::string name;
    int budget = 0;
};

class Employee {
 public:
    explicit Employee();
    explicit Employee(std::string, std::string, std::string);
    explicit Employee(std::string, std::string, std::string, int, int);
    void setWorkTime(int);
    void setPayment(int);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    int getWorkTime();
    std::string getName();
    std::string getPosition();
    std::string getId();
    int getPayment();

 private:
    std::string id;
    std::string name;
    std::string position;
    int worktime = 0;
    int payment = 0;
};
#endif  // INCLUDE_EMPLOYEE_H_
