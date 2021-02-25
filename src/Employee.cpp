#include "Employee.h"
#include <string>

Employee::Employee(int id, std::string name, Position position) {
    this->id = id;
    this->name = name;
    this->position = position;
}

void Employee::setWorkTime(int wtime) {
    this->worktime = wtime;
}

std::string Employee::getName() {
    return this->name;
}

Position Employee::getPosition() {
    return this->position;
}

int Employee::getWorktime() {
    return this->worktime;
}
int Employee::getPayment() {
    return this->payment;
}
