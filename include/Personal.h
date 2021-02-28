// Copyright 2021 dmitrycvetkov2000
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Interfaces.h"
#include "Employee.h"

#include <string>

class Personal : public WorkBaseTime, public Employee {
 public:
    virtual ~Personal() = default;

    int calcBase() const override;

 protected:
    Personal(int id, const std::string& name,
        Position position, int salary);

    int salary;
};

class Driver : public Personal {
 public:
    Driver(int id, const std::string& name, int salary);

    int calcBonus() const override;
    void calc() override;

    void printInfo() const override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, const std::string& name, int salary);

    int calcBonus() const override;
    void calc() override;

    void printInfo() const override;
};


#endif  // INCLUDE_PERSONAL_H_
