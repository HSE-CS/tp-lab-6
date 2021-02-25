// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum class Position {
    DRIVER, CLEANER, PROJECT_MANAGER, SENIOR_MANAGER,
    ENGINEER, TESTER, PROGRAMMER, TEAM_LEAD
};

class Employee {
 public:
    void setWorkTime(unsigned int wtime);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    Employee(unsigned int id, std::string name,
        Position position);
    std::string getName();
    Position getPosition();
    unsigned int getWorktime();
    unsigned int getPayment();

 protected:
    unsigned int id;
    std::string name;
    Position position;
    unsigned int worktime;
    unsigned int payment;
};

#endif  // INCLUDE_EMPLOYEE_H_
