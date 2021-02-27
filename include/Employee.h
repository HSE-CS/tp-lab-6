#pragma once

#include <string>

#include "Interfaces.h"

class Employee {
public:
    Employee(unsigned int id,
            std::string name,
            Position position,
            unsigned int worktime,
            unsigned int payment);
    void setWorkTime(unsigned int worktime);
    void setPayment(unsigned int payment);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
protected:
    unsigned int id;
    std::string name;
    Position position;
    unsigned int worktime;
    unsigned int payment;
};