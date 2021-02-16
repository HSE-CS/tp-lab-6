// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

class Employee {
private:
    int id;
    std::string name;
    std::string position;
    int worktime;
    double payment;
public:
    Employee(int id, std::string name,
        std::string position, double payment);
    void setWorktime(int worktime);
    void setPayment(double payment);
    int getWorktime();
    double getPayment();
    int getId();
    std::string getName();
    std::string getPosition();
    virtual double calc() = 0;
    virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_