// Copyright 2021 Ziganshin Nikita

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <iostream>
#include <string>

class Personal : public Employee, public WorkBaseTime {
 protected:
    unsigned int salary;  // (per hour)
 public:
    Personal(unsigned int id, std::string name, unsigned int salary);

    unsigned int calcBase() override;

    unsigned int calcBonus() override = 0;

    void calc() override = 0;

    void printInfo() override = 0;

    unsigned int getSalary() const;

    void setSalary(unsigned int salary);
};

class Driver : public Personal {
 private:
    unsigned int additionalWorkTime = 0;
 public:
    Driver(unsigned int id, std::string name, unsigned int salary);

    unsigned int calcBonus() override;

    void calc() override;

    void printInfo() override;

    unsigned int getAdditionalWorkTime() const;

    void setAdditionalWorkTime(unsigned int additionalWorkTime);
};

class Cleaner : public Personal {
 public:
    Cleaner(unsigned int id, std::string name, unsigned int salary);

    unsigned int calcBonus() override;

    void calc() override;

    void printInfo() override;
};

#endif  // INCLUDE_PERSONAL_H_
