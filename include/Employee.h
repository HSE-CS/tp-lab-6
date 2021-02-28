// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <random>
#include <fstream> 
#include "Interfaces.h"

class Employee {
 private:
    int ID;
    std::string name;

 protected:
    std::string position;
    int worktime = 0;
    int payment = 0;

 public:
    Employee(int ID, std::string name) {
        this->ID = ID;
        this->name = name;
    }
    void addWorkTime(int time) {
        worktime += time;
    }
    void setToZero() {
        worktime = 0;
    }
    void printInfo() {
        std::cout << "ID: " << ID << "\nName: " << name <<
        "\nPosition: " << position << "\nWork time: " <<
        worktime << "\nPayment: " << payment << std::endl;
    }
};

#endif   // INCLUDE_EMPLOYEE_H_
