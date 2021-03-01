// Copyright 2021 Bekina Svetlana
#include "Personal.h"

Personal::Personal() {}

int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

int Personal::getSalary() {
    return salary;
}

void Personal::printInfo() {
    std::cout << "\nName: " << getName() << "\t" << getId() << std::endl;
    std::cout << "\nSalary: " << getSalary() <<
        "\tWork time: " << getWorkTime() << std::endl;
    std::cout << "\nPayment: " << getPayment() << "\n\n";
}

int Personal::calcBonus() {
    return calcBase(getSalary(), getWorkTime()) * 0.1;
}

Driver::Driver() {}

int Driver::calcBonus() {
    return calcBase(getSalary(), getWorkTime()) * 0.2;
}

void Driver::calc() {
    setPayment(calcBase(getSalary(), getWorkTime()) + calcBonus());
}

Cleaner::Cleaner() {}

void Cleaner::calc() {
    setPayment(calcBase(getSalary(), getWorkTime()));
}
