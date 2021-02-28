// Copyright 2021 Egor Buzanov

#include "Employee.h"

void Employee::setWorktime(int _worktime) { worktime = _worktime; }

int Employee::getId() const { return id; }

std::string Employee::getName() const { return name; }

POSITIONS Employee::getPosition() const { return position; }

int Employee::getWorktime() const { return worktime; }

int Employee::getPayment() const { return payment; }
