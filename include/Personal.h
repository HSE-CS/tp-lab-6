// Copyright 2021 valvarl

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public IWorkBaseTime {
 protected:
    int salary;
 public:
    Personal(int id, const std::string &name, Position position, int salary);
    void printInfo() override;
    int calcBase(int salary, int wtime) override;
    int calcBonus() override;
    void calc() override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, const std::string &name, Position position, int salary);
};

class Driver : public Personal {
 public:
    Driver(int id, const std::string &name, Position position, int salary);
    int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
