#include "Personal.h"
// Copyright 2021 Khoroshavina Ekaterina

double Personal::getSalary() {
    return calc() + calcBase(getPayment(), getWorktime());
}

double Personal::calc() {
    return 0;
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


double Driver::getSalary() {
    return calc() + calcBonus();
}

double Driver::calc() {
    return getPayment() * getWorktime();
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
    std::cout << "Id:" << getId() << std::endl;
    std::cout << "Name:" << getName() << std::endl;
    std::cout << "Position:" << getPosition() << std::endl;
    std::cout << "Payment:" << getPayment() << std::endl;
    std::cout << "Salary:" << getSalary() << std::endl;
    std::cout << "==============" << std::endl;
}
