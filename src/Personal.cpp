// Copyright 2021 BekusovMikhail

#include "Personal.h"

#include <utility>
#include <iostream>

int Personal::calcBase(int salary, int wTime) {
    return salary * wTime;
}

void Personal::setSalary(int salary) {
    this->salary = salary;
}

int Personal::getSalary() {
    return this->salary;
}

void Personal::printInfo() {
    std::cout << this->name << "(" <<
              this->position << "). Payment: " << this->payment << std::endl;
}

Cleaner::Cleaner(std::string id, std::string name, Position position,
                 int salary) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->salary = salary;
}

void Cleaner::calc() {
    this->payment = calcBase(this->salary, this->workTime);
}

int Cleaner::calcBonus() {
    return 0;
}

Driver::Driver(std::string id, std::string name, Position position,
               int salary) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->workTime = workTime;
    this->salary = salary;
}

void Driver::calc() {
    this->payment = calcBase(this->salary, this->workTime) + calcBonus();
}

int Driver::calcBonus() {
    if (this->workTime <= 40) {
        return 0;
    } else {
        return 2 * this->salary * (this->workTime - 40);
    }
}
