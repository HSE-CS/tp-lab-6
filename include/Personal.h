// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public WorkBaseTime {
protected:
    int salary{};
public:
    int calcBase(int salary, int wTime) override;

    void setSalary(int salary);

    int getSalary();

    void printInfo() override;
};

class Cleaner : public Personal {
public:
    Cleaner(std::string id, std::string name, Position position, int salary);

    void calc() override;

    int calcBonus() override;
};

class Driver : public Personal {
public:
    Driver(std::string id, std::string name, Position position, int salary);

    void calc() override;

    int calcBonus() override;
};

#endif //INCLUDE_PERSONAL_H_
