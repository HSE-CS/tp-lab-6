// Copyright 2021 valvarl

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_


#include <string>

enum Position {
    SENIOR_MANAGER,
    PROJECT_MANAGER,
    TEAM_LEADER,
    PROGRAMMER,
    TESTER,
    DRIVER,
    CLEANER
};

class Employee {
 protected:
    int id;
    std::string name;
    Position position;
    int workTime;
    int payment;
 public:
    Employee(int id, std::string name, Position position);
    void setWorkTime(int workTime);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    std::string getPosition() const;

    int getPayment() const;
};


#endif  // INCLUDE_EMPLOYEE_H_
