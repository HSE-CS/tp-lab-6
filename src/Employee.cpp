//
// Created by Valera on 20.02.2021.
//

#include "../include/Employee.h"

#include <utility>

void Employee::setWorkTime(int _workTime) {
    Employee::workTime = _workTime;
}

Employee::Employee(int id, std::string name, Position position) :
id(id), name(std::move(name)), position(position) {}
