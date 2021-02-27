// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//
#include "Employee.h"

Employee::Employee(id_type id, const std::string& name) :
    _id(id),
    _name(name),
    _payment(0),
    _worktime(0)
{}

void Employee::set_worktime(unsigned int wt) {
  _worktime = wt;
}
