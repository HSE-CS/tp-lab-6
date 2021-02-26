// Copyright 2021 JGMax

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee, public WorkBaseTime {
 protected:
    int salary;
    double bonus;
 public:
    Personal(int id,
             std::string fullName,
             int workTime,
             Position position,
             int salary,
             double bonus = 0);
    void calc() override;
    void printInfo() override;
    int calcBase() override;
    int calcBonus() override;
};

class Driver: public Personal {
 public:
    Driver(int id,
           std::string fullName,
           int workTime,
           Position position,
           int salary,
           double bonus);
};

class Cleaner: public Personal {
 public:
    Cleaner(int id,
            std::string fullName,
            int workTime,
            Position position,
            int salary);
};

#endif  // INCLUDE_PERSONAL_H_
