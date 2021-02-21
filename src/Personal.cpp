#include "Personal.h"
// Copyright 2021 Khoroshavina Ekaterina

// class Personal

void Personal::setSalary(double salary) {
    this->salary = salary;
}

double Personal::getSalary() {
    return calc();
}

double Personal::calc() {
    return calcBase(getPayment(), getWorktime()) + calcBonus();
}

double Personal::calcBase(double payment, int time) {
    return payment * time;
}

double Personal::calcBonus() {
    return 0;
}

void Personal::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id:" << getId() << std::endl;
    std::cout << "Name:" << getName() << std::endl;
    std::cout << "Position:" << getPosition() << std::endl;
    std::cout << "Payment:" << getPayment() << std::endl;
    std::cout << "Salary:" << getSalary() << std::endl;
    std::cout << "==============" << std::endl;
}

// class Driver

void Driver::setSalary(double salary) {
    Personal::setSalary(salary);
}

double Driver::getSalary() {
    return calcBase(getPayment(), getWorktime()) + calcBonus();
}

double Driver::calc() {
    this->setSalary(calcBase(getPayment(), getWorktime()) + calcBonus());
    return calcBase(getPayment(), getWorktime()) + calcBonus();
}

double Driver::calcBase(double payment, int time) {
    return Personal::calcBase(payment, time);
}

double Driver::calcBonus() {
    if (getWorktime() > 40) {
        return (getWorktime() * (getPayment() * 2));
    }
    else {
        return 0.0;
    }
}

void Driver::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "==============" << std::endl;
}

// class Cleaner

void Cleaner::setSalary(double salary) {
    Personal::setSalary(salary);
}

double Cleaner::getSalary() {
    return calcBase(getPayment(), getWorktime()) + calcBonus();
}

double Cleaner::calc() {
    this->setSalary(calcBase(getPayment(), getWorktime()) + calcBonus());
    return calcBase(getPayment(), getWorktime()) + calcBonus();
}

double Cleaner::calcBase(double payment, int time) {
    return Personal::calcBase(payment, time);
}

double Cleaner::calcBonus() {
    if (getWorktime() > 30) {
        return (double(getWorktime()) * (getPayment() * 1,5));
    }
    else {
        return 0.0;
    }
}

void Cleaner::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id:" << getId() << std::endl;
    std::cout << "Name:" << getName() << std::endl;
    std::cout << "Position:" << getPosition() << std::endl;
    std::cout << "Payment:" << getPayment() << std::endl;
    std::cout << "Salary:" << getSalary() << std::endl;
    std::cout << "==============" << std::endl;
}
