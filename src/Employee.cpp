// Copyright 2021 JGMax

#include "Employee.h"

Employee::Employee(const int id,
                   const std::string fullName,
                   const int workTime,
                   const Position position) {
    this->id = id;
    this->fullName = fullName;
    this->workTime = workTime;
    this->position = position;
    payment = 0;
}

void Employee::setWorkTime(const int workTime) {
    this->workTime = workTime;
}

std::string Employee::getFullName() const {
    return fullName;
}

int Employee::getWorkTime() const {
    return workTime;
}

double Employee::getPayment() const {
    return payment;
}

std::string Employee::getPosition() const {
    switch (position) {
        case PERSONAL:
            return "Personal";
        case DRIVER:
            return "Driver";
        case CLEANER:
            return "Cleaner";
        case TESTER:
            return "Tester";
        case ENGINEER:
            return "Engineer";
        case PROGRAMMER:
            return "Programmer";
        case TEAM_LEADER:
            return "Team Leader";
        case PROJECT_MANAGER:
            return "Project manager";
        case SENIOR_MANAGER:
            return "Senior manager";
    }
    return "None";
}

Position Employee::getPositionId() const {
    return position;
}

int Employee::getId() const {
    return id;
}

