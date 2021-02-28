// Copyright 2021 MalininDmitry

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public IWorkBaseTime {
 protected:
    int salary;
 public:
    Personal(unsigned int id, std::string name,
             std::string position, unsigned int payment, int salary);

    int calcBase(int salary, int wtime) override;
    int calcBonus() override;
    void printInfo() override;
    void calc() override;
};

class Driver : public Personal{
 public:
    Driver(unsigned int id, std::string name,
           std::string position, unsigned int payment);
};

class Cleaner : public Personal{
 public:
    Cleaner(unsigned int id, std::string name,
            std::string position, unsigned int payment);
};


#endif  // INCLUDE_PERSONAL_H_

