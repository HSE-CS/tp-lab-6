// Copyright 2021 Sozinov Kirill

#include "Employee.h"

Employee::Employee(int _id, std::string _name, std::string _position) {
   id = _id;
   name = _name;
   position = _position;
   worktime = 0;
}

void Employee::setWorkTime(int wt) {
    worktime = wt;
}

std::string Employee::getName() {
    return name;
}

int Employee::getId() {
    return id;
}

std::string Employee::getPosition() {
    return position;
}

int Employee::getWorktime() {
    return worktime;
}

int Employee::getPayment() {
    return payment;
}