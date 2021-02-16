// Copyright 2021 soda
#include "Interfaces.h"

//
//void Employee::setWorkTime(size_t time) {
//    Employee::worktime = time;
//}
//
//void Employee::setPayment(int p) {
//    Employee::payment = p;
//}

size_t Employee::getWorktime() {
    return worktime;
}

size_t Employee::getPayment() {
    return payment;
}

size_t Employee::getId() {
    return id;
}

std::string& Employee::getName() {
    return name;
}

size_t Employee::getPositionID() {
    return position;
}

std::string Employee::getPosition() {
    if (this->position == 1)
        return std::string("MANAGER");
}
