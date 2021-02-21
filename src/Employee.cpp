// Copyright 2021 soda
#include "Interfaces.h"


void Employee::setId(size_t id) {
    this->id = id;
}

void Employee::setName(std::string& name) {
    this->name = name;
}

void Employee::setWorkTime(size_t worktime) {
    this->worktime = worktime;
}

void Employee::setPosition(size_t position) {
    this->position = position;
}

void Employee::setPayment(size_t payment) {
    this->payment = payment;
}

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
    else if (this->getPositionID() == 2)
        return std::string("CLEANER");
    else if (this->getPositionID() == 3)
        return std::string("SECURITY");
    else if (this->getPositionID() == 4)
        return std::string("ENGINEER");
    else if (this->getPositionID() == 5)
        return std::string("PROGRAMMER");
    else if (this->getPositionID() == 6)
        return std::string("TESTER");
    else if (this->getPositionID() == 7)
        return std::string("TEAMLEADER");
    else if (this->getPositionID() == 8)
        return std::string("MANAGER");
    else if (this->getPositionID() == 9)
        return std::string("SENIORMANAGER");
    else
        return std::string("I don't know, sorry!");
}
