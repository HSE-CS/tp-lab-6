// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee, public WorkBaseTime {
 private:
    int salary;

 public:
    Personal(int id, std::string name, std::string pos,
         int worktime, int payment)
        :Employee(id, name, pos, worktime, payment) {}
    int getSalary();
    int calcBase(int salary, int wtime) override;
    int calcBonus() override;
    int calc() override;
    void printInfo() override;
};

class Clener: public Personal {
 public:
    Clener(int id, std::string name, std::string pos, int worktime, int payment)
        :Personal(id, name, pos, worktime, payment) {}
    int calc() override;
    int calcBonus() override;
    void printInfo() override;
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name, std::string pos, int worktime, int payment)
        :Personal(id, name, pos, worktime, payment) {}
    int calc() override;
    int calcBonus() override;
    void printInfo() override;
    int calcBase(int salary, int wtime) override;
};
#endif  // INCLUDE_PERSONAL_H_
