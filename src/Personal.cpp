// Copyright 2021 Ziganshin Nikita

#include "Personal.h"

unsigned int Personal::calcBase() {
    return salary * workTime;
}

unsigned int Personal::getSalary() const {
    return salary;
}

void Personal::setSalary(unsigned int salary) {
    this->salary = salary;
}

Personal::Personal(unsigned int id, std::string name, unsigned int salary) {
    this->id = id;
    this->name = std::move(name);
    position = driver;
    this->salary = salary;
}

unsigned int Driver::calcBonus() {
    return salary * additionalWorkTime;
}

void Driver::calc() {
    payment = calcBase() + calcBonus();
}

void Driver::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Driver" << std::endl
              << "Work time: " << workTime << std::endl << "Payment: " << payment << std::endl << "Salary: " << salary
              << std::endl << "Additional work time: " << additionalWorkTime << std::endl;
}

unsigned int Driver::getAdditionalWorkTime() const {
    return additionalWorkTime;
}

void Driver::setAdditionalWorkTime(unsigned int additionalWorkTime) {
    Driver::additionalWorkTime = additionalWorkTime;
}

Driver::Driver(unsigned int id, std::string name, unsigned int salary) : Personal(id, name, salary) {
    this->position = driver;
}

void Cleaner::calc() {
    payment = calcBase();
}

void Cleaner::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Cleaner" << std::endl
              << "Work time: " << workTime << std::endl << "Payment: " << payment << std::endl << "Salary: " << salary
              << std::endl;
}

unsigned int Cleaner::calcBonus() {
    return 0;
}

Cleaner::Cleaner(unsigned int id, std::string name, unsigned int salary) : Personal(id, name, salary) {
    this->position = cleaner;
}
