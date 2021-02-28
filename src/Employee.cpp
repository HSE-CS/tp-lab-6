// Copyright 2021 FOM
#include "Employee.h"
#include <fstream>
#include <string>
#include <cmath>

Employee::Employee(int id, std::string name, std::string position,
    int worktime, int payment) {
    this->id = id;
    this->name = name;
    this->position = position;
    this->worktime = worktime;
    this->payment = payment;
}
int Employee::getId() {
    return id;
}
std::string Employee::getName() {
    return name;
}
std::string Employee::getPosition() {
    return position;
}
void Employee::setWorkTime(size_t wtime) {
    this->worktime = wtime;
}
int Employee::getWorkTime() {
    return worktime;
}
int Employee::getPayment() {
    return payment;
}
