// Copyright 2021 Bekina Svetlana
#include "Employee.h"

Employee::Employee() {}

Employee::Employee(std::string new_id,
    std::string new_name, std::string new_position) {
    id = new_id;
    name = new_name;
    position = new_position;
}

Employee::Employee(std::string new_id,
    std::string new_name, std::string new_position,
    int new_payment, int new_worktime) {
    id = new_id;
    name = new_name;
    position = new_position;
    payment = new_payment;
    worktime = new_worktime;
}

void Employee::setWorkTime(int wtime) {
    worktime = wtime;
}

void Employee::setPayment(int pay) {
    payment = pay;
}

int Employee::getWorkTime() {
    return worktime;
}

std::string Employee::getName() {
    return name;
}

std::string Employee::getPosition() {
    return position;
}

std::string Employee::getId() {
    return id;
}

int Employee::getPayment() {
    return payment;
}
