// Copyright 2021 dmitrycvetkov2000
#include "Employee.h"

#include <string>

Employee::Employee(const int id,
    const std::string& name,
    const Position position) : id(id),
    name(name),
    position(position) {
}

void Employee::setWorkTime(const int wtime) {
    worktime = wtime;
}
