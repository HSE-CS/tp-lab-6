// Copyright 2021
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>

class Employee {

protected:
    int id;
    std::string name;
    std::string position;
    int worktime = 0;
    double payment = 0;
public:
    Employee(int id,std::string name,
        std::string position)
        : id(id),
        name(std::move(name)),
        position(std::move(position)) {}
    void setWorkTime();
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    std::string getName();
    int getWorkTime();
    double getPayment();
};
#endif  // INCLUDEEMPLOYEE_H_
