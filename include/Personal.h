// Copyright 2021 GN
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 private:
    int salary;

 public:
    explicit Personal(int id_, std::string name_,
        int salary_) : Employee(id_, name_) {
        salary = salary_;
    }
    int getSalary();
    virtual int calcBase(int salary_, int worktime_);
    virtual int calcBonus() { return 0; }
    virtual void printInfo();
};

class Cleaner : public Personal {
 public:
    explicit Cleaner(int id_, std::string name_,
        int salary_) : Personal(id_, name_, salary_) {
        spec = CLEANER;
    }
    virtual void calc();
};

class Driver : public Personal {
 private:
     bool bonus = 0;
 public:
    explicit Driver(int id_, std::string name_,
        int salary_) : Personal(id_, name_, salary_) {
        spec = DRIVER;
    }
    virtual int calcBonus();
    virtual void calc();
    void addBonus() {
        bonus = 1;
    }
};

#endif  // INCLUDE_PERSONAL_H_
