// Copyright 2021 kostinandrey
#include "Employee.h"
Project::Project(int id, int budget, int number_of_employee) {
    this->id = id;
    this->budget = budget;
    this->number_of_employees = number_of_employee;
}
int Project::get_num_of_employees() const {
    return this->number_of_employees;
}
int Project::get_budget() const {
    return this->budget;
}
Employee::Employee(int id, std::string name,
                   int work_time, Positions position) {
    this->id = id;
    this->name = std::move(name);
    this->payment = 0;
    this->position = position;
    this->work_time = work_time;
}
