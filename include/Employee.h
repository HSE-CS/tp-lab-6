// Copyright 2021 Islam Osmanov

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <iostream>
#include <string>

class Employee {
 private:
    int id;
    std::string position;
    std::string name;
    int payment = 0;
    int worktime = 0;
    int salary = 0;
 public:
    Employee(int curr_id, std::string some_name,
             std::string pos, int sal);
    int getId();
    void setPosition(std::string pos);
    std::string &getPosition();
    std::string &getName();
    int getWorkTime();
    int getPayment();
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    void setPayment(int pay);
    void setWorkTime(int time);
};

#endif  // INCLUDE_EMPLOYEE_H_
