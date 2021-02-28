// Copyright 2020 Golovanov
#include "Interfaces.h"
#include "Employee.h"

void Employee::set_id(int id) {
    this->id = id;
}
void Employee::set_name(std::string& name) {
    this->name = name;
}
void Employee::set_worktime(int worktime) {
    this->worktime = worktime;
}
void Employee::set_position(std::string& position) {
    if ((position != "Engineer") && (position != "Cleaner") &&
        (position != "Driver") && (position != "Programmer") &&
        (position != "Tester") && (position != "TeamLeader") &&
        (position != "ProjectManager") && (position != "SeniorManager")) {
        std::cout << "Such a profession does not exist! Try again";
    } else {
        this->position = position;
    }
}
void Employee::set_payment(int payment) {
    this->payment = payment;
}
int Employee::get_id() {
    return id;
}
std::string& Employee::get_name() {
    return name;
}
int Employee::get_worktime() {
    return worktime;
}
std::string Employee::get_position() {
    return position;
}
int Employee::get_payment() {
    return payment;
}
