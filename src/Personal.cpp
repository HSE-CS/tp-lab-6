//  Copyright 2021 Nikita Naumov
#include "Personal.h"

Personal::Personal(unsigned id, const std::string& name) : Employee(id, name) {
    this->id = id;
    this->name = name;
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

Driver::Driver(unsigned int id, std::string name) : Personal(id, name) {
    this->id = id;
    this->name = name;
    this->salaryPerHour = 0;
    this->additionalHours = rand()%51;
    setPosition(2);
}

unsigned Driver::calcBonus() {
    return additionalHours * this->salaryPerHour * 2;
}

void Driver::calc() {
    this->payment = calcBase(this->salaryPerHour, this->worktime) + calcBonus();
}

Cleaner::Cleaner(unsigned int id, std::string name) : Personal(id, name) {
    this->id = id;
    this->name = name;
    this->salaryPerHour = 0;
    setPosition(1);
}