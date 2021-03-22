//
// Created by stoja on 12.03.2021.
//
#include "Employee.h"

Employee::Employee(unsigned int id, std::string name, Position position) {
    this->id = id;
    this->name = name;
    this->position = position;
}

void Employee::setWorkTime(unsigned int workTime) {
    this->workTime = workTime;
}

void Employee::printPosition() {
    switch (position) {
        case 0:
            std::cout << "\nPosition: engineer\n";
            break;
        case 1:
            std::cout << "\nPosition: programmer\n";
            break;
        case 2:
            std::cout << "\nPosition: tester\n";
            break;
        case 3:
            std::cout << "\nPosition: team leader\n";
            break;
        case 4:
            std::cout << "\nPosition: project manager\n";
            break;
        case 5:
            std::cout << "\nPosition: senior manager\n";
            break;
        case 6:
            std::cout << "\nPosition: driver\n";
            break;
        case 7:
            std::cout << "\nPosition: cleaner\n";
            break;

    }
}

unsigned int Employee::getId() const {
    return id;
}

const std::string &Employee::getName() const {
    return name;
}

double Employee::getPayment() const {
    return payment;
}
