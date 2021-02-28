// Copyright 2021 MalininDmitry
#include <iostream>
#include <string>
#include "Employee.h"

void Employee::setWorkTime(unsigned int worktime) {
    this->worktime = worktime;
}

Employee::Employee(int id, std::string name, std::string position,
                   unsigned int salary) {
    this->id = id;
    this->name = name;
    this->position = position;
    this->salary = salary;
}

Employee::Employee(int id, std::string name, std::string position) {
    this->id = id;
    this->name = name;
    this->position = position;
    this->salary = 0;
}

unsigned int Employee::getPayment() {
    return payment;
}

unsigned int Employee::getWorktime() {
    return worktime;
}

unsigned int Employee::getSalary() {
    return salary;
}

std::string Employee::getPosition() {
    return position;
}

std::string Employee::getName() {
    return name;
}
