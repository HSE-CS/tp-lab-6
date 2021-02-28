// Copyright 2021 dmitrycvetkov2000
#include "Personal.h"

#include <iostream>
#include <string>

Personal::Personal(const int id,
    const std::string& name,
    const Position position,
    const int salary) : Employee(id, name, position),
    salary(salary) {
}

int Personal::calcBase() const {
    return salary * worktime;
}

Driver::Driver(int id,
    const std::string& name,
    int salary) : Personal(id,
        name,
        Position::Driver,
        salary) {
}

int Driver::calcBonus() const {
    const int nightHours = 8;
    return nightHours * salary * 0.5;
}

void Driver::calc() {
    payment = calcBase() + calcBonus();
}

void Driver::printInfo() const {
    std::cout << "Driver " << name << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Base payment: " << calcBase() << std::endl;
    std::cout << "Bonus: " << calcBonus() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}

Cleaner::Cleaner(int id,
    const std::string& name,
    int salary) : Personal(id,
        name,
        Position::Cleaner,
        salary) {
}

int Cleaner::calcBonus() const {
    return 0;
}

void Cleaner::calc() {
    payment = calcBase();
}

void Cleaner::printInfo() const {
    std::cout << "Cleaner " << name << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Payment: " << payment << std::endl;
}
