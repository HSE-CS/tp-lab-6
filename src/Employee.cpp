// Copyright 2021
#include "Employee.h"
#include <iostream>

void Employee::setWorkTime() {
    this->worktime = std::rand() % 72;
}

std::string Employee::getName() {
    return name;
}

int Employee::getWorkTime() {
    return worktime;
}

double Employee::getPayment() {
    return payment;
}
