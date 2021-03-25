// Copyright 2021 dash
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

#include "Interfaces.h"

enum Position {
    ENGINEER,
    PROGRAMMER,
    TESTER,
    TEAMLEADER,
    PROJECTMANAGER,
    SENIORMANAGER,
    DRIVER,
    CLEANER
};

class Employee {
 public:
    explicit Employee(int id_, std::string name_, Position position_) {
        id = id_;
        name = name_;
        position = position_;
    }
    void set_Worktime(int wt);
    void virtual calc() = 0;
    void virtual print_Info() = 0;
    void set_Payment(int p);
    int get_Id();
    const std::string& get_Name();
    Position get_Position();
    unsigned int get_Worktime();
    unsigned int get_Payment();
 protected:
    int id;
    std::string name;
    Position position;
    int worktime;
    int payment;
};

#endif  // INCLUDE_EMPLOYEE_H_
