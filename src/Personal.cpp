/// Copyright 2021 GN
#include "Employee.h"
#include "Personal.h"
#include <iostream>
int Personal::getSalary() {
    return salary;
}
int Personal::calcBase(int salary_, int worktime_) {
    return salary_ * worktime_;
}
void Cleaner::calc() {
    setPayment(calcBase(getSalary(), getWorkTime()));
}
int Driver::calcBonus() {
    if (bonus == 1) { return 100; }
    return 0;
}
void Driver::calc() {
    setPayment(calcBase(getSalary(), getWorkTime()) + calcBonus());
}
void Personal::printInfo() {
    std::cout << getName() + " " + std::to_string(getID());
}
