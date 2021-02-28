//  Copyright 2021 Nikita Naumov
#include "Personal.h"

Personal::Personal(unsigned id, const std::string& name) : Employee(id, name) {
    this->id = id;
    this->name = std::move(name);
    setPosition(0);
    this->payment = 0;
    this->salaryPerHour = 0;
}

void Personal::setSalaryPerHour(int _salaryPerHour) {
    this->salaryPerHour = _salaryPerHour;
}

unsigned Personal::getSalaryPerHour() {
    return (this->salaryPerHour);
}

unsigned Personal::calcBase(unsigned _salaryPerHour, unsigned workTime) {
    return (_salaryPerHour * workTime);
}

void Personal::calc() {
    this->payment = calcBase(this->salaryPerHour, this->worktime);
}

Driver::Driver(unsigned int id, const std::string& name)
                : Personal(id, name) {
    this->id = id;
    this->name = std::move(name);
    this->salaryPerHour = 0;
    this->additionalHours = std::rand()%51;
    setPosition(2);
}

void Driver::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " <<
                convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Current additional hours " <<
                this->additionalHours << std::endl;
    std::cout << "Salary per hour " << this->salaryPerHour << std::endl;
    std::cout << "Current payment " << this->payment << std::endl;
}

unsigned Driver::calcBonus() {
    return additionalHours * this->salaryPerHour * 2;
}

void Driver::calc() {
    this->payment = calcBase(this->salaryPerHour, this->worktime)
                    + calcBonus();
}

int Driver::getAdditionalHours() {
    return this->additionalHours;
}

Cleaner::Cleaner(unsigned int id, const std::string& name)
        : Personal(id, name) {
    this->id = id;
    this->name = std::move(name);
    this->salaryPerHour = 0;
    setPosition(1);
}

unsigned int Cleaner::calcBonus() {
    return 0;
}

void Cleaner::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " <<
    convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Salary per hour " << this->salaryPerHour << std::endl;
    std::cout << "Current payment " << this->payment << std::endl;
}
