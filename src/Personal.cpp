// Copyright [2020] <Olesya Nikolaeva>

#include "Personal.h"

int Personal::calcBase(int salary, int worktime) {
    return salary * worktime;
}

void Personal::printInfo() {
    std::cout << "ID: " << ID << "\nName: " << name <<
    "\nPosition: " << position << "\nWork time: " <<
    worktime << "\nPayment: " << payment << "\nSalary: " << salary
    << std::endl;
}

void Driver::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

int Driver::calcBonus() {
    if (worktime > 30) {
        return 200;
    }
    return 0;
}

void Cleaner::calc() {
    payment = calcBase(salary, worktime);
}

