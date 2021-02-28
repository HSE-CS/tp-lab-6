#include "Employee.h"

void Employee::setWorktime(int worktime) {
    this->worktime = worktime;
}

int Employee::getId() {
    return id;
}

std::string Employee::getName() {
    return name;
}

Position Employee::getPosition() {
    return position;
}

std::string Employee::positionToString() {
    std::string result = "";
    switch (getPosition()) {
    case 1:
        result = "Enginer";
        break;
    case 2:
        result = "Cleaner";
        break;
    case 3:
        result = "Driver";
        break;
    case 4:
        result = "Programmer";
        break;
    case 5:
        result = "Tester";
        break;
    case 6:
        result = "Team Leader";
        break;
    case 7:
        result = "Project Manager";
        break;
    case 8:
        result = "Senior Manager";
        break;
    }
    return result;
}

int Employee::getWorktime() {
    return worktime;
}

int Employee::getPayment() {
    return payment;
}

void Employee::setPayment(int payment) {
    this->payment = payment;
}

Employee::Employee(int id, std::string name, Position position, int worktime) {
    this->id = id;
    this->name = name;
    this->position = position;
    setWorktime(worktime);
    this->payment = 0;
}