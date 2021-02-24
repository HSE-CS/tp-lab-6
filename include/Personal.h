//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public WorkBaseTime {
 public:
    Personal(int id, int worktime,
             int payment, int salary,
             std::string name,
             std::string position) : Employee(
                    id, worktime, payment,
                    payment * worktime,
                       name, position) {
    }

    int calc() override;
    int calcBase(int payment, int wtime) override;
    int calcBonus() override;
    void printInfo() override;
};

class Driver : public Personal {
 public:
    Driver(int id, int worktime,
           int payment, int salary,
           std::string name,
           std::string position)
            : Personal(
            id, worktime, payment,
            payment * worktime,
            name, position) {}

    int calcBonus() override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, int worktime,
            int payment, int salary,
            std::string name,
            std::string position)
            : Personal(
            id, worktime, payment,
            payment * worktime,
            name, position) {}
    int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
