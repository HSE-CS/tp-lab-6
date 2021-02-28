//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "Personal.h"

unsigned Personal::getSalary() {
    return this->salary;
}
unsigned Personal::calcBase(unsigned salary, unsigned worktime) {
    return salary * worktime;
}

unsigned Personal::calcBonus() {
    return 0;
}

unsigned Personal::calc() {
    this->payment = calcBase(this->salary, this->worktime) + calcBonus();
    return this->payment;
}

void Personal::printInfo() {
    Employee::printInfo();
}

void Driver::printInfo() {
    std::cout << name << " (id: " << id << ")" << std::endl;
    std::cout << "<Position: " <<
    positionToString(this->position) << "> ";
    std::cout << "<Worktime: " << worktime << "> ";
    std::cout << "<Payment: " << payment
    << " (nights: " << nightHours << ")>";
    std::cout << std::endl << std::endl;
}

void Driver::setNightHours(unsigned hours) {
    this->nightHours = hours;
}

unsigned Driver::calcBonus() {
    return nightHours * salary * 0.25;
}
