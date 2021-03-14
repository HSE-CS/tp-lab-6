// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"


class Personal: public Employee {
 protected:
    int salary;

 public:
    Personal(std::string ID, std::string name, std::string position, int salary) : Employee(ID, name, position) {
        this->salary = salary;
        this->position = position;
    }
    void printInfo();
    virtual int calcBase(int salary, int worktime);
};


class Driver: public Personal {
 public:
    Driver(std::string ID, std::string name, int salary) :
    Personal(ID, name, "driver", salary) {
        position = "driver";
    }
    void calc();
    virtual int calcBonus();
};

class Cleaner: public Personal {
 public:
    Cleaner(std::string ID, std::string name, int salary) :
    Personal(ID, name, "cleaner", salary) {
        position = "cleaner";
    }
    void calc();
};

#endif   // INCLUDE_PERSONAL_H_
