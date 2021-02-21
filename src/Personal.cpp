// Copyright 2021 soda
#include "Interfaces.h"

#include "Employee.h"
#include "Personal.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


void Personal::setSalary(size_t salary) {
    this->salary = salary;
}

size_t Personal::getSalary() {
    return salary;
}

size_t Personal::calcBase() {
    return (this->getWorktime() * this->getSalary());
}

Driver::Driver(size_t id, std::string name, size_t worktime,
    size_t position, size_t salary) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->setPayment(this->calc());
}

size_t Driver::calc() {
    return (this->calcBonus() + this->calcBase());
}

size_t Driver::calcBonus() {
    unsigned int seed = time(NULL);
    return rand_r(&seed) % 10000;
}


void Driver::printInfo() {
    std::cout << std::endl <<this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nSalary = " << this->getSalary()
        << " Worktime = " << this->getWorktime() << "; Final payment = "
        << this->getPayment()<< std::endl;
}

Cleaner::Cleaner(size_t id, std::string name, size_t worktime,
    size_t position, size_t salary) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->setPayment(this->calc());
}

size_t Cleaner::calc() {
    return (this->calcBase());
}


void Cleaner::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName() <<
        " - "
        << this->getPosition() << "\nSalary = " << this->getSalary()
        << " Worktime = " << this->getWorktime() << "; Final payment = "
        << this->getPayment() << std::endl;
}

Security::Security(size_t id, std::string name, size_t worktime,
    size_t position, size_t salary, size_t killed) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->killed_enemies = killed;
    this->setPayment(this->calc());
}

size_t Security::getKilled() {
    return this->killed_enemies;
}

size_t Security::calcBonus() {
    return this->getKilled() * 15000;
}

size_t Security::calc() {
    return (this->calcBonus() + this->calcBase());
}

void Security::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - " << this->getPosition() << "\nSalary = " << this->getSalary()
        << " Worktime = " << this->getWorktime() << " Killed = "
        << this->getKilled() << "; Final payment = "
        << this->getPayment() << std::endl;
}
