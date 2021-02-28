// Copyright 2021 Kris


#ifndef PERSONAL_INCLUDE_H_
#define PERSONAL_INCLUDE_H_
#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee {
private:
    int salary;
public:
    Personal(int id_, std::string name_, std::string position_, int pay);
    Personal();
    void setsalary(int a) {
        salary = a;
    }
    int calc();
    void printInfo();
    int calcBase();
    int getsalary();
};

class Driver: public Personal {
private:
    int nighttime = 0;
    int nightpayment =0;
public:
    Driver(int _id, std::string _name, std::string _pos, int _payment);
    Driver(int nightti, int nightpay) {
        nighttime = nightti;
        nightpayment = nightpay;
    }
    int calcBonus();
    int calc();
};

class Cleaner: public Personal {
 public:
    Cleaner(int _id, std::string _name, std::string _pos, int _payment);
    int calc();
};

class Project {
private:
    int id;
    int budget;
public:
    Project() {
        id = 0;
        budget = 0;
    }
    Project(int _id, int _budget);
    int getId();
    int getBudget();
};

#endif // !PERSONAL_INCLUDE_H_
