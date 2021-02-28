// Copyright 2021 Kris

#ifndef INCLUDE_EMPLOEE_H_
#define INCLUDE_EMPLOEE_H_

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Employee {
 private:
    int id;
    std::string name;
    std::string position;
    int worktime;
    int payment;
 public:
    Employee();
    Employee(int id_, std::string name_, std::string position_, int pay);
    void setWorkTime(int wt);
    int getid();
    int getworktime();
    int getpayment();
    std::string getname();
    std::string getposition();
    virtual int calc() = 0;
    virtual void printInfo() = 0;
};


#endif   // !INCLUDE_EMPLOEE_H_
