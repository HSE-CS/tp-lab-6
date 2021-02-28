// Copyright 2021 dmitrycvetkov2000
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum class Position {
    Programmer = 1,
    Tester,
    TeamLeader,
    Driver,
    Cleaner,
    ProjectManager,
    SeniorManager,
    Engineer,
};

class Employee {
 public:
    virtual ~Employee() = default;

    void setWorkTime(int wtime);
    virtual void calc() = 0;
    virtual void printInfo() const = 0;

 protected:
    Employee(int id, const std::string &name, Position position);

    int id;
    std::string name;
    Position position;
    int worktime;
    int payment;
};


#endif   // INCLUDE_EMPLOYEE_H_
