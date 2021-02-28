// Copyright 2021 Islam Osmanov

#include "Employee.h"

Employee::Employee(int curr_id,
                   std::string some_name,
                   std::string pos,
                   int sal) {
    this->id = curr_id;
    this->name = some_name;
    this->position = pos;
}

void Employee::setPosition(std::string pos) {
    this->position = pos;
}
int Employee::getId() {
    return this->id;
}

std::string& Employee :: getPosition() {
    return this->position;
}

std::string& Employee::getName() {
    return this->name;
}

void Employee::setPayment(int pay) {
    this->payment = pay;
}

int Employee::getWorkTime() {
    return this->worktime;
}

void Employee::setWorkTime(int time) {
    this->worktime = time;
}

int Employee::getPayment() {
    return this->payment;
}
