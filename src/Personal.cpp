//
// Created by stoja on 12.03.2021.
//

#include "Personal.h"

#include <utility>

Personal::Personal(unsigned int id, std::string name, Position position, unsigned int salaryPerHour) :
        Employee(id, std::move(name), position) {
    this->salaryPerHour = salaryPerHour;
}

int Personal::calcBase(int salaryPerHour, int workTime) {
    return salaryPerHour * workTime;
}

void Personal::printInfo() {
    printPosition();
    std::cout << "ID: " << id << "\nName: " << name << "\nWork time: " << workTime << "\nSalary per hour: "
              << salaryPerHour << "\nPayment: " << payment;
}

Cleaner::Cleaner(unsigned int id, std::string name, Position position, unsigned int salaryPerHour)
: Personal(id, std::move(name), position, salaryPerHour) {}

void Cleaner::calc() {
    this->payment = calcBase(salaryPerHour, workTime);
}

int Cleaner::calcBonus() {
    return 0;
}

Driver::Driver(unsigned int id, std::string name, Position position, unsigned int salaryPerHour)
: Personal(id, std::move(name), position, salaryPerHour) {}

int Driver::calcBonus() {
    return nightHours * salaryPerHour * 2;
}

void Driver::setNightHours(int nightHours) {
    this->nightHours = nightHours;
}

void Driver::calc() {
    this->payment = calcBase(salaryPerHour, workTime) + calcBonus();
}

void Driver::printInfo() {
    std::cout << "ID: " << id << "\nName: " << name << "\nWork time: " << workTime << "\nSalary per hour: "
              << salaryPerHour
              << "\nBonus: " << calcBonus() << "\nPayment: " << payment;
}

