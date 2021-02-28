// Copyright 2021 Sozinov Kirill

#include "Personal.h"

Personal::Personal(int _id, std::string _name,
    std::string _position, int _salary)
    : Employee(_id, _name, _position), salary(_salary) {}

int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

int Personal::calcBonus() {
    return 0;
}

void Personal::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

void Personal::printInfo() {
    std::cout << id << ": " << name << ", position: " <<
        position << ", salary: " << salary << "total payment: "
        << payment << std::endl;
}

Cleaner::Cleaner(int _id, std::string _name, std::string _position, int
    _salary) : Personal(_id, _name, _position, _salary) {}


Driver::Driver(int _id, std::string _name, std::string _position, int
    _salary) : Personal(_id, _name, _position, _salary) {}

int Driver::calcBonus() {
    if (worktime > 8)
        return salary * 2 * (worktime - 8);
}
