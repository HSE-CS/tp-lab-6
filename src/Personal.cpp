#include "Personal.h"
#include <iostream>

void Personal::printInfo() {
    std::cout << "id: " << getId() << "\tname: " << getName() << 
        "\nPosition: " << positionToString() << "\tWorktime: " << worktime <<
        "\nPayment: " << payment << std::endl;
    std::cout << "=====================================" << std::endl;
}

int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

Personal::Personal(int id, std::string name, Position position,
    int worktime, int salary) : Employee(id, name, position, worktime) {
    this->salary = salary;
}

Driver::Driver(int id, std::string name, Position position,
    int worktime, int salary) :
    Personal(id, name, position, worktime, salary) {
}

int Driver::calcBonus() {
    if (getWorktime() > 40) {
        return calcBase(this->salary, this->getWorktime()) * 0.1;
    }
}

Cleaner::Cleaner(int id, std::string name, Position position,
    int worktime, int salary) :
    Personal(id, name, position, worktime, salary) {
}

void Driver::calc() {
    this->setPayment(calcBase(this->salary, this->worktime) + calcBonus());
}

void Cleaner::calc() {
    this->setPayment(calcBase(this->salary, this->worktime));
}

int Cleaner::calcBonus() {
    return 0;
}