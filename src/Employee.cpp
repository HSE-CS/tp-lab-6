//  Copyright 2021 Nikita Naumov

#include "Employee.h"

#include <utility>

Employee::Employee(unsigned id, std::string name) {
    this->id = id;
    this->name = std::move(name);
    this->position = Unemployed;
    this->worktime = 0;
    this->payment = 0;
}

Employee::~Employee() {
    this->name.clear();
    this->position = Unemployed;
    this->worktime = 0;
    this->payment = 0;
}

void Employee::setPosition(int numOfPosition) {
    this->position = static_cast<Position>(numOfPosition);
}

void Employee::setWorkTime(unsigned workedTime) {
    this->worktime = workedTime;
}