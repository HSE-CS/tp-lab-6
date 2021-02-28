// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"

class Personal: public Employee, public WorkBaseTime {
 private:
    int salary;

 public:
    Personal(int ID, std::string name, int salary) : Employee(ID, name) {
       this->salary = salary;
    }
    void calcBase() {
        
    }
    virtual int calcBase(int salary, int worktime);
};

class Driver: public Personal {
 public:
    Driver(int ID, std::string name, int salary) : Personal(ID, name, salary) {
        position = "driver";
    }
    void calc() {}
};

class Cleaner: public Personal {
 public:
    Cleaner(int ID, std::string name, int salary) : Personal(ID, name, salary) {
        position = "cleaner";
    }
    void calc() {}
};

#endif   // INCLUDE_PERSONAL_H_
