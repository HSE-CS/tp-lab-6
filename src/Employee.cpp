// Copyright 2021 asma
#include "Employee.h"
#include <string>

void Employee::SetWorkTime(int time) {
    worktime = time;
}

int Employee::GetId() const {
    return id;
}

int Employee::GetPayment() const {
    return payment;
}

std::string Employee::GetName() const {
    return name;
}

int Employee::GetWorkTime() const {
    return worktime;
}
