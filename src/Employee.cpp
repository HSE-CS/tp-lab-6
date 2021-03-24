// Copyright 2021 dash
#include "Interfaces.h"
#include "Employee.h"

void Employee::set_Worktime(int wt) { worktime = wt; }

void Employee::set_Payment(int p) { payment = p; }

unsigned int Employee::get_Id() { return id; }

std::string& Employee::get_Name() { return name; }

Position Employee::get_Position() { return position; }

unsigned int Employee::get_Worktime() { return worktime; }

unsigned int Employee::get_Payment() { return payment; }