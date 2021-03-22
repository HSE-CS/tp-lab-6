// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <iostream>
#include <string>
enum Position {
    ENGINEER,
    PROGRAMMER,
    TESTER,
    TEAM_LEADER,
    PROJECT_MANAGER,
    SENIOR_MANAGER,
    DRIVER,
    CLEANER
};

class Employee {
 protected:
    Employee(unsigned int id, std::string name, Position position);
    Position position;
    unsigned int id;
    std::string name;
    double payment;
    unsigned int workTime = 0;

 public:
    const std::string &getName() const;

    void setWorkTime(unsigned int);

    void printPosition();

    virtual void calc() = 0;

    virtual void printInfo() = 0;

    unsigned int getId() const;

    double getPayment() const;
};

#endif  // INCLUDE_EMPLOYEE_H_
