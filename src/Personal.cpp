// Copyright 2021 Shatilov Victor

#include "Personal.h"

#include <iostream>

Personal::Personal(int id, std::string name,
                   int workTime, int salary, Positions position)
        : Employee(id, std::move(name), workTime, position), salary(salary) {}

int Personal::calcBase() {
    return salary * workTime;
}

int Personal::calcBonus(int bonus) {
    return bonus * salary;
}

int Personal::calc() {
    return payment = calcBase() + calcBonus();
}

void Personal::printInfo() {
    std::cout << name << " on " << this->getPositionAsStr() << std::endl;
    std::cout << "With payment: " << payment << std::endl;
    std::cout << "Work time: " << workTime <<std::endl;
}

Driver::Driver(int id, const std::string& name,
               int workTime, int salary, Positions position) :
        Personal(id, name, workTime, salary, position) {
}

int Driver::calc() {
    return payment = calcBase() + calcBonus();
}

int Driver::calcBonus(int bonus) {
    return bonus * salary;
}


Cleaner::Cleaner(int id, const std::string& name,
                 int workTime, int salary, Positions position) :
        Personal(id, name, workTime, salary, position) {
}

int Cleaner::calcBonus(int bonus) {
    return bonus * salary;
}
int Cleaner::calc() {
    return payment = calcBase() + calcBonus();
}
