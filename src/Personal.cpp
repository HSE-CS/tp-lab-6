// Copyright 2021 valvarl

#include <sstream>
#include <iostream>
#include "../include/Personal.h"

int Personal::calcBase(int _salary, int _wtime) {
    return _salary*_wtime;
}

int Personal::calcBonus() {
    return 0;
}

Personal::Personal(int id, const std::string &name, Position position,
                   int salary) : Employee(id, name, position), salary(salary) {}

void Personal::printInfo() {
    std::stringbuf str;
    std::ostream stream(&str);
    stream << "Id: " << id << "\nName: " << name << "\nPosition: " <<
    getPosition() << "\nWork time: " << workTime << "\nSalary: " << salary
    << "\nPayment: " << payment << "\n";
    std::cout << str.str() << std::endl;
}

void Personal::calc() {
    payment =  calcBase(salary, workTime) + calcBonus();
}

Cleaner::Cleaner(int id, const std::string &name, Position position, int salary)
        : Personal(id, name, position, salary) {}

int Driver::calcBonus() {
    return calcBase(salary, workTime) / 10;
}

Driver::Driver(int id, const std::string &name, Position position, int salary)
        : Personal(id, name, position, salary) {}
