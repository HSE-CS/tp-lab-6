//  Copyright 2021 Nikita Naumov

#include "Employee.h"

#include <utility>

Employee::Employee(unsigned id, const std::string& name) {
    this->id = id;
    this->name = std::move(name);
    setPosition(0);
    this->worktime = 0;
    this->payment = 0;
}
std::string Employee::convertPositionToString() {
    switch (this->position) {
        case 0:
            return "Unemployed";
        case 1:
            return "Cleaner";
        case 2:
            return "Driver";
        case 3:
            return "Manager";
        case 4:
            return "Programmer";
        case 5:
            return "Senior Manager";
        case 6:
            return "Team Leader";
        case 7:
            return "Tester";
    }
    return "Unemployed";
}

unsigned int Employee::getPosition() {
    return (this->position);
}

void Employee::setPosition(int numOfPosition) {
    this->position = static_cast<Position>(numOfPosition);
}

void Employee::setWorkTime(unsigned workedTime) {
    this->worktime = workedTime;
}