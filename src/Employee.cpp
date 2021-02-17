// Copyright 2021 soda
#include "Interfaces.h"



void Employee::setId(size_t id) {
    this->id = id;
}

void Employee::setWorkTime(size_t time) {
    this->worktime = time;
}


void Employee::setPosition(size_t position) {
    this->position = position;
}

void setName(std::string);
void setWorkTime(size_t);
void setPosition(size_t);
void setPayment(size_t);



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
    if (this->getPositionID() == 1)
        return std::string("DRIVER");
}
