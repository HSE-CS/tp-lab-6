// Copyright 2021 GN
#include "Employee.h"
void Employee::setPayment(int payment_) {
    payment = payment_;
}
void Employee::setWorkTime(int worktime_) {
    worktime = worktime_;
}
int Employee::getWorkTime() {
    return worktime;
}
std::string Employee::getName() {
    return name;
}
int Employee::getID() {
    return id;
}
int Employee::getPayment() {
    return payment;
}
position Employee::getPos() {
    return spec;
}
