// Copyright [2021] <Roman Balayan>

#include "Personal.h"

int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

Personal::Personal(unsigned int id,
                    std::string name,
                    Position position,
                    unsigned int worktime,
                    unsigned int payment,
                    unsigned int salary)
    : Employee(id, name, position, worktime, payment)
    , salary(salary) {

}

Driver::Driver(unsigned int id,
    std::string name,
    unsigned int worktime,
    unsigned int payment,
    unsigned int salary)
    : Personal(id, name, Position::Driver, worktime, payment, salary) {

}

int Driver::calcBonus() {
    if (this->worktime > 6 * 20)
        return 10 * (this->worktime - 6 * 20);
    return 0;
}

void Driver::calc() {
    this->payment = calcBase(this->salary, this->worktime) + calcBonus();
}

void Driver::printInfo() {
    std::cout << "Driver info:\n";
}

Cleaner::Cleaner(unsigned int id,
    std::string name,
    unsigned int worktime,
    unsigned int payment,
    unsigned int salary)
    : Personal(id, name, Position::Cleaner, worktime, payment, salary) {

}

void Cleaner::calc() {
    this->payment = calcBase(this->salary, this->worktime);
}

void Cleaner::printInfo() {
    std::cout << "Cleaner info:\n";
}