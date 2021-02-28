// Copyright 2020 Golovanov
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include <vector>

#include "Interfaces.h"
#include "Employee.h"


class Personal : public Employee {
private:
    int salary;

public:
    Personal(int id, std::string name, std::string position, int salary,
        int worktime)
        : Employee(id, name, position, 0, worktime), salary(salary) {}
    void set_salary(int salary);
    int calcBase(int time, int salary);
    int get_salary();
};

class Driver : public Personal {
public:
    Driver(int id, std::string name, std::string position, int payment,
        int worktime)
        : Personal(id, name, position, payment, worktime) {}
    int calcBonus();
    int calc();
    void printInfo();
};

class Cleaner : public Personal {
public:
    Cleaner(int id, const std::string name, const std::string position,
        int payment, int worktime)
        : Personal(id, name, position, payment, worktime) {}
    int calc();
    void printInfo();
};

#endif  // INCLUDE_PERSONAL_H_