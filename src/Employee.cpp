//
// Created by Данил on 28.02.2021.
//

#include "../include/Employee.h"

#include <utility>

void Employee::setWorkTime(int hours) {
    this->worktime = hours;
}

Project *Employee::getProject() {
    return this->project;
}

int Employee::getPosition() {
    return this->position;
}

Employee::Employee(std::string name1,
                   int worktime1,
                   Project *project1,
                   int position1) {
    this->name = std::move(name1);
    this->worktime = worktime1;
    this->project = project1;
    this->position = position1;
    this->payment = 0;
    this->id = this->getId();
}
