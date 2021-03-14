// Copyright [2020] <Olesya Nikolaeva>

#include "Employee.h"


std::string Employee::returnID() {
    return ID;
}

std::string Employee::returnPosition() {
    return position;
}

int Employee::returnPayment() {
    return payment;
}

void Employee::addWorkTime(int time) {
    worktime += time;
}

void Employee::setToZero() {
    worktime = 0;
}

void Employee::printInfo() {
    std::cout << "ID: " << ID << "\nName: " << name <<
    "\nPosition: " << position << "\nWork time: " <<
    worktime << "\nPayment: " << payment << std::endl;
}
