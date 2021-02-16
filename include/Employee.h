// Copyright 2021 soda
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <vector>
#include <string>
#include "Interfaces.h"


class Employee {
 private:
     size_t id;
     std::string name;
     size_t worktime;
     size_t payment;
     size_t position;
 public:
     Employee();
     void setWorkTime();
     virtual void calc() = 0;
     virtual void printInfo() = 0;
    ~Employee();
};

#endif  // INCLUDE_DEANARY_H_