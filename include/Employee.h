// Copyright 2021 soda
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <vector>
#include <string>
#include "Interfaces.h"


class Employee {
private:
    size_t id;
    std::string name;
    size_t worktime;
    size_t position;
    size_t payment;

public:
    void setId(size_t);
    void setName(std::string&);
    void setWorkTime(size_t);
    void setPosition(size_t);
    void setPayment(size_t);

    size_t getWorktime();
    size_t getPayment();
    size_t getId();
    std::string& getName();
    size_t getPositionID();
    std::string getPosition();
    size_t virtual calc() = 0;
    void virtual printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
