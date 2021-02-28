// Copyright 2021 Islam Osmanov

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"


class Personal: public Employee, public WorkBaseTime {
 private:
    int salary = 0;
 public:
    Personal(int id, int salary,
             std::string position, std::string name);
    int calcBase(int sal, int wtime) override;
    int calcBonus(int bonus) override;
    void setSalary(int sal);
    int getSalary();
};

class Cleaner: public Personal {
 public:
    Cleaner(int id, int salary,
                     std::string position, std::string name);
    void printInfo() override;
    void calc() override;
};

class Driver : public Personal {
 public:
    void printInfo() override;
    void calc() override;
    int calcBonus(int bonus) override;
    Driver(int id, int salary,
                     std::string position,
                     std::string name);
};
#endif  // INCLUDE_PERSONAL_H_
