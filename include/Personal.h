// Copyright Baklanov 2021
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>
#include "Employee.h"
#include "Factory.h"
#include "Interfaces.h"

class WorkBaseTime;

class Personal : public WorkBaseTime, public Employee {
 protected:
    int salary;

 public:
    Personal(int id_,
        std::string position_,
        std::string name_,
        int worktime_,
        int payment_,
        int salary_) :
        Employee(id_,
            position_,
            name_,
            worktime_,
            payment_),
        salary(salary_) {}
    int calcBase(int salary, int worktime) override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id_,
        std::string position_,
        std::string name_,
        int worktime_,
        int payment_,
        int salary_) :
        Personal(id_, position_,
            name_,
            worktime_,
            payment_,
            salary_) {}
    void printinfo() override;
    void calc() override;
    int calcBonus() override;
};

class Driver : public Personal {
 public:
    Driver(int id_, std::string position_,
        std::string name_,
        int worktime_,
        int payment_,
        int salary_) :
        Personal(id_, position_,
            name_, worktime_,
            payment_, salary_) {}
    void calc() override;
    int calcBonus() override;
    void printinfo() override;
};

#endif  // INCLUDE_PERSONAL_H_

