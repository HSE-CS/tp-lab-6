// Copyright 2021 BekusovMikhail

#include "Employee.h"

#include <utility>

void Employee::setId(std::string id) {
    this->id = std::move(id);
}

void Employee::setName(std::string name) {
    this->name = std::move(name);
}

void Employee::setPosition(Position position) {
    this->position = position;
}

void Employee::setWorkTime(int workTime) {
    this->workTime = workTime;
}

void Employee::setPayment(int payment) {
    this->payment = payment;
}

std::string Employee::getId() {
    return this->id;
}

std::string Employee::getName() {
    return this->name;
}

Position Employee::getPosition() {
    return this->position;
}

int Employee::getWorkTime() {
    return this->workTime;
}

int Employee::getPayment() {
    return this->payment;
}
