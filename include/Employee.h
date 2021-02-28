// Copyright 2021 Kris

#ifndef EMPLOEE_INCLUDE_H_
#define EMPLOEE_INCLUDE_H_

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


#endif // !EMPLOEE_INCLUDE_H_
