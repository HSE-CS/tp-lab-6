// Copyright 2021 Kris

#include "Employee.h"

void Employee::setWorkTime(int wt) {
    this->worktime = wt;
}

int Employee::getid() {
    return id;
}
int Employee::getworktime() {
    return worktime;
}
int Employee::getpayment() {
    return payment;
}
std::string Employee::getname() {
    return name;
}
std::string Employee::getposition() {
    return position;
}

Employee::Employee(int id_, std::string name_, std::string position_, int pay) {
    id = id_;
    name = name_;
    position = position_;
    payment = pay;
}

Employee::Employee() {
    id = 0;
    name = "";
    position = "";
    payment = 0;
}

int Employee::calc() {
    return getworktime() * getpayment();
}

void Employee::printInfo() {
    std::cout << std::setw(8) << getid() << std::setw(16) << getname() << std::setw(16) << getposition() << std::setw(4) << getworktime() << std::setw(5) << getpayment() << std::endl;
}
