// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"

class Personal : public Employee, IWorkBaseTime {
 private:
    double salary = 0;
 public:
    Personal(int id, std::string name,
        std::string position, double payment) :
        Employee(id, name, position, payment) {}
    void setSalary(double salary) override;
    double getSalary() override;
    double calc() override;
    double calcBase(double payment, int time) override;
    double calcBonus() override;
    void printInfo() override;
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name,
        std::string position, double payment) :
        Personal(id, name, position, payment) {}
    void setSalary(double salary) override;
    double getSalary() override;
    double calc() override;
    double calcBase(double payment, int time) override;
    double calcBonus() override;
    void printInfo() override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name,
        std::string position, double payment) :
        Personal(id, name, position, payment) {}
    void setSalary(double salary) override;
    double getSalary() override;
    double calc() override;
    double calcBase(double payment, int time) override;
    double calcBonus() override;
    void printInfo() override;
};

#endif  // INCLUDE_PERSONAL_H_
