// Copyright 2021 Khoroshavina Ekaterina
#include "Employee.h"
#include <string>

Employee::Employee(int id, std::string name,
    std::string position, double payment) {
    Employee::id = id;
    Employee::name = std::move(name);
    Employee::position = std::move(position);
    Employee::payment = payment;
}

void Employee::setWorktime(int worktime) {
    Employee::worktime = worktime;
}

void Employee::setPayment(double payment) {
    Employee::payment = payment;
}

int Employee::getWorktime() {
    return worktime;
}

double Employee::getPayment() {
    return payment;
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
