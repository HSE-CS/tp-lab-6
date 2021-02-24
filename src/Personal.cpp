// Copyright 2021 Igumnova Natasha
#include "Personal.h"
#include <fstream>
#include <string>
#include <cmath>

int Personal::getSalary() {
    salary = calc() + calcBonus();
    return salary;
}
int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

int Personal::calcBonus() {
    int bonus = static_cast<int>(getPayment() * getWorktime() * 0.3);
    return bonus;
}

int Personal::calc() {
    return getPayment() * getWorktime();
}
void Personal::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
       + "\nname " + getName() + "\nposition " + getPosition()
       + "\npayment " + std::to_string(getPayment())
       + "\nsalary " + std::to_string(getSalary());
    std::cout << res << std::endl;
}

int Clener::calc() {
    return Personal::calc();
}
void Clener::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(getSalary());
    std::cout << res << std::endl;
}

int Clener::calcBonus() {
    return 0;
}

int Driver::calc() {
    return Personal::calc();
}
int Driver::calcBase(int salary, int wtime) {
    return Personal::calcBase(salary, wtime);
}

void Driver::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(getSalary());
    std::cout << res << std::endl;
}

int Driver::calcBonus() {
    return Personal::calcBonus();
}
