// Copyright 2021 Igumnova Natasha
#include "Employee.h"
#include <fstream>
#include <string>
#include <cmath>

Employee::Employee(int id_, std::string name_, std::string pos_,
        int worktime_, int payment_) {
    id = id_;
    name = name_;
    pos = pos_;
    worktime = worktime_;
    payment = payment_;
}
void Employee::setWorkTime(int w) {
    worktime = w;
}
std::string Employee::getPosition() {
    return pos;
}
int Employee::getId() {
    return id;
}
std::string Employee::getName() {
    return name;
}
int Employee::getWorktime() {
    return worktime;
}
int Employee::getPayment() {
    return payment;
}
