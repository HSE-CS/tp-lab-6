// Copyright 2021 Kartseva Masha
#include "Employee.h"
#include <map>

extern std::map<std::string, int> projects;

Employee::Employee(std::string name, int id) {
    this->name = name;
    this->id = id;
    worktime = 0;
}

unsigned int Employee::getId() const {
    return id;
}

unsigned int Employee::getWorkTime() const {
    return worktime;
}

std::string Employee::getName() const {
    return name;
}

void Employee::setWorkTime(unsigned int time) {
    this->worktime = time;
}
