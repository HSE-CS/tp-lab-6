// Copyright 2021 valvarl

#include "../include/Employee.h"

#include <utility>

void Employee::setWorkTime(int _workTime) {
    Employee::workTime = _workTime;
}

Employee::Employee(int id, std::string name, Position position) :
id(id), name(std::move(name)), position(position), payment(0) {}

std::string Employee::getPosition() const {
    std::string result;
    if (position == CLEANER) result =  "cleaner";
    else if (position == DRIVER) result = "driver";
    else if (position == PROGRAMMER) result = "programmer";
    else if (position == TESTER) result = "tester";
    else if (position == TEAM_LEADER) result = "team_leader";
    else if (position == PROJECT_MANAGER) result = "project_manager";
    else result = "senior_manager";
    return result;
}

int Employee::getPayment() const {
    return payment;
}
