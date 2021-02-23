//// Copyright 2021 Dmitry Vargin

#include "Employee.h"

Employee::Employee() {}

Employee::Employee(int id, std::string name, std::string position) {
    this->id = id;
    this->name = name;
    this->position = position;
}

Employee::Employee(int id, int worktime, double payment,
                   double salary, std::string name,
                   std::string position) {
    this->id = id;
    this->name = name;
    this->worktime = worktime;
    this->payment = payment;
    this->salary = salary;
    this->position = position;
}

Employee::Employee(const Employee& employee) {
    this->id = employee.id;
    this->position = employee.position;
    this->worktime = employee.worktime;
    this->name = employee.name;
    this->payment = employee.payment;
}

Employee::~Employee() {}

void Employee::setPayment(double payment) {
    this->payment = payment;
}

void Employee::setWorktime(int worktime) {
    this->worktime = worktime;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

void Employee::setPosition(std::string position) {
    this->position = position;
}

std::string Employee::getName() const {
    return this->name;
}

int Employee::getId() const {
    return this->id;
}
int Employee::getWorktime() const {
    return this->worktime;
}
double Employee::getPayment() const {
    return this->payment;
}

double Employee::getSalary() const {
    return this->salary;
}

std::string Employee::getPosition() const {
    return this->position;
}
