// Copyright 2021 TimurZaytsev
//

#include "Employee.h"

Employee::Employee(id_type id, const std::string& name) :
    _id(id),
    _nameof(name),
    _payment(0),
    _timeofwork(0)
{}

void Employee::worktime(unsigned int wt) {
    _timeofwork = wt;
}
