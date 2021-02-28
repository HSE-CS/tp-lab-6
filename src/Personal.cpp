// Copyright 2021 TimurZaytsev
//

#include <Personal.h>
#include <iostream>

Personal::Personal(id_type id, const std::string& name, unsigned int salary) :
    Employee(id, name),
    _salary(salary)
{}


int Personal::calc_base(int salary, int wt) {
    return salary / 10 * wt / 2;
}

Cleaner::Cleaner(id_type id, const std::string& name, unsigned int salary) :
    Personal(id, name, salary)
{
    _position = Position::Cleaner;
}

int Cleaner::calc_bonus() {
    return 0;
}

void Cleaner::calc() {
    _payment = calc_base(_salary, _timeofwork) + calc_bonus();
}

void Cleaner::print_info() {
    std::cout << "Position: Cleaner\n"
        "ID: " << _id << '\n' <<
        "Name: " << _nameof << '\n' <<
        "Worktime: " << _timeofwork << '\n' <<
        "Payment: " << _payment << std::endl;
}

Driver::Driver(id_type id, const std::string& name, unsigned int salary) :
    Personal(id, name, salary)
{
    _position = Position::Driver;
}

int Driver::calc_bonus() {
    return _salary / 100 * _timeofwork;
}

void Driver::calc() {
    _payment = calc_base(_salary, _timeofwork) + calc_bonus();
}

void Driver::print_info() {
    std::cout << "Position: Driver\n"
        "ID: " << _id << '\n' <<
        "Name: " << _nameof << '\n' <<
        "Worktime: " << _timeofwork << '\n' <<
        "Payment: " << _payment << std::endl;
}
