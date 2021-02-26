// Copyright 2021 Khoroshavina Ekaterina
#include "Employee.h"
#include <string>

Employee::Employee(int id, std::string name,
    std::string position, double payment) {
    this->id = id;
    this->name = std::move(name);
    this->position = std::move(position);
    this->payment = payment;
}

void Employee::setWorktime(int worktime) {
    this->worktime = worktime;
}

void Employee::setPayment(double payment) {
    this->payment = payment;
}

int Employee::getWorktime() {
    return worktime;
}

double Employee::getPayment() {
    return payment;
}

double Employee::getSalary() {
    return calc();
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
