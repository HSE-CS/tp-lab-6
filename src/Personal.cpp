// copyright 2021 Toliman

#include "../include/Personal.h"

#include <utility>

int Personal::calcBase(int salary_, int wtime) {
    return salary_ * wtime;
}

Personal::Personal(std::string name1,
                   int worktime1,
                   Project *project1,
                   int position1,
                   int salary1) : Employee(std::move(name1),
                                           worktime1,
                                           project1,
                                           position1) {
    this->salary = salary1;
}

void Driver::calcBonus(int nightHours) {
    this->payment += calcBase(this->salary, nightHours);
}

void Driver::calc(int hours) {
    this->payment += calcBase(this->salary, hours);
}

void Driver::printInfo() {
    toStringForm(this->name,
        this->id,
        this->position,
        this->project);
}

Driver::Driver(std::string name1,
               int worktime1,
               Project *project1,
               int position1,
               int salary1) : Personal(std::move(name1),
                                       worktime1,
                                       project1,
                                       position1,
                                       salary1) {}

int Driver::getPayment() {
    return this->payment;
}

void Cleaner::calc(int hours) {
    this->payment += calcBase(this->salary, hours);
}

void Cleaner::printInfo() {
    toStringForm(this->name,
        this->id,
        this->position,
        this->project);
}

void Cleaner::calcBonus(int floors) {
    this->payment += calcBase(this->salary, floors);
}

Cleaner::Cleaner(std::string name1,
                 int worktime1,
                 Project *project1,
                 int position1,
                 int salary1) : Personal(std::move(name1),
                                         worktime1,
                                         project1,
                                         position1,
                                         salary1) {}

int Cleaner::getPayment() {
    return this->payment;
}
