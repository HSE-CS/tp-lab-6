// Copyright 2021 dash
#include "Personal.h"

int Personal::calcBase(int salary, int worktime) {
    return salary * worktime;
}

Personal::Personal(int id,
    std::string name,
    Position position,
    int worktime,
    int payment,
    int salary)
    : Employee(id, name, position)
    , salary(salary) {

}

Driver::Driver(int id,
    std::string name,
    Position position,
    int worktime,
    int payment,
    int salary) : Personal(id,
        name,
        position,
        worktime,
        payment,
        salary) {
}

Cleaner::Cleaner(int id,
    std::string name,
    Position position,
    int worktime,
    int payment,
    int salary) : Personal(id,
        name,
        position,
        worktime,
        payment,
        salary) {
}


int Driver::calcBonus() {
    if (this->worktime > 6 * 20)
        return 10 * (this->worktime - 6 * 20);
    return 0;
}

void Driver::calc() {
    int payment = calcBase(salary, worktime) + calcBonus();
}

void Driver::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}


void Cleaner::calc() {
    int payment = calcBase(salary, worktime) + calcBonus();
}


void Cleaner::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}