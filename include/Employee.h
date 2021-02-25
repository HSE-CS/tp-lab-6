// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum class Position {
    DRIVER = 0, CLEANER = 1, PROJECT_MANAGER = 2,
    SENIOR_MANAGER = 3,
    ENGINEER = 4, TESTER = 5, PROGRAMMER = 6, TEAM_LEAD = 7
};

class Employee {
 public:
    void setWorkTime(int wtime);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    Employee(int id, std::string name,
        Position position);
    std::string getName();
    Position getPosition();
    int getWorktime();
    int getPayment();

 protected:
    int id;
    std::string name;
    Position position;
    int worktime;
    int payment;
};

#endif  // INCLUDE_EMPLOYEE_H_
