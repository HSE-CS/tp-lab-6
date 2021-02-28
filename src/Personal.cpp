// Copyright 2021 Kris

#include "Personal.h"
Personal::Personal(int _id, std::string _name, 
    std::string _pos, int _payment) : 
    Employee(_id, _name, _pos, _payment) {
    salary = 0;
}

Driver::Driver(int _id, std::string _name, 
    std::string _pos, int _payment) : 
    Personal(_id, _name, _pos, _payment) {
    setsalary(0);
}

Cleaner::Cleaner(int _id, std::string _name, 
    std::string _pos, int _payment) : 
    Personal(_id, _name, _pos, _payment) {
    setsalary(0);
}

Personal::Personal() {
    salary = 0;
}

int Personal::getsalary() {
    return salary;
}

int Project::getId() {
    return id;
}

int Project::getBudget() {
    return budget;
}

Project::Project(int _id, int _budget) {
    id = _id;
    budget = _budget;
}

int Personal::calcBase() {
    int a = (getworktime()) * (getpayment());
    return a;
}

int Driver::calcBonus() {
    return nighttime * nightpayment;
}

int Personal::calc() {
    return getworktime() * getpayment();
}

void Personal::printInfo() {
    std::cout << std::setw(8)<< getid() << std::setw(16) <<
        getname()<< std::setw(16)<< getposition()<<
        std::setw(4)<< getworktime() << std::setw(5)<<
        getpayment()<< std::setw(8) << getsalary() << std::endl;
}

int Driver::calc() {
    setsalary(calcBase() + calcBonus());
    return calcBase() + calcBonus();
}

int Cleaner::calc() {
    setsalary(calcBase());
    return calcBase();
}
