// Copyright 2021 asma
#pragma once
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Project.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

enum Position {PROGRAMMER, TESTER, TEAMLEADER,
    SENIORMANAGER, ENGINEER, PROJECTMANAGER, DRIVER, CLEANER};

class Employee {
 public:
    void SetWorkTime(int);
    int GetId() const;
    int GetPayment() const;
    std::string GetName() const;
    int GetWorkTime() const;
    virtual void Calc() = 0;
    virtual void PrintInfo() const = 0;
    virtual std::string GetPosition() const = 0;
 protected:
    int id;
    std::string name;
    Position position;
    int worktime;
    int payment;
};

#endif  // EMPLOYEE_H_
