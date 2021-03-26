#include "Employee.h"

void Employee::setWorkTime(unsigned int workTime) {
    Employee::workTime = workTime;
}

unsigned int Employee::getPayment() const {
    return payment;
}

unsigned int Employee::getId() const {
    return id;
}

void Employee::setId(unsigned int id) {
    this->id = id;
}

const std::string &Employee::getName() const {
    return name;
}

void Employee::setName(const std::string &name) {
    this->name = name;
}

unsigned int Employee::getWorkTime() const {
    return workTime;
}

Position Employee::getPosition() const {
    return position;
}

void Employee::setPosition(Position position) {
    this->position = position;
}
