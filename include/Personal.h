#pragma once

#include <iostream>

#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public IWorkBaseTime {
public:
    virtual int calcBase(int salary, int wtime) override;
protected:
    Personal(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary);
    unsigned int salary;
};

class Driver : public Personal {
public:
    Driver(unsigned int id,
        std::string name,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary);
    virtual int calcBonus() override;
    virtual void calc() override;
    virtual void printInfo() override;
};

class Cleaner : public Personal {
public:
    Cleaner(unsigned int id,
        std::string name,
        unsigned int worktime,
        unsigned int payment,
        unsigned int salary);
    virtual void calc() override;
    virtual void printInfo() override;
};