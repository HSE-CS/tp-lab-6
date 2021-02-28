// Copyright 2021 Bogomazov

#include "../include/Engineer.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int Engineer::calcBudgetPart(float part, int budget) {
    return part * budget;
}
double Engineer::getPart() {
    return part;
}
int Engineer::calc() {
    return Personal::calc();
}
void Engineer::printInfo() {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Work time: " << getWorkTime() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
}

int Tester::calcProAdditions() {
    return Personal::calc() * 0.2;
}
int Tester::calc() {
    return Engineer::calc() + calcProAdditions();
}
void Tester::printInfo() {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Work time: " << getWorkTime() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
}

int Programmer::calcProAdditions() {
    return Personal::calc() * 0.3;
}
int Programmer::calc() {
    return Engineer::calc() + calcProAdditions();
}

void Programmer::printInfo() {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Work time: " << getWorkTime() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
}

int TeamLeader::calcHeads() {
    return 32354;
}

int TeamLeader::calc() {
    return Engineer::calc() + calcProAdditions() + calcHeads();
}

void TeamLeader::printInfo() {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Work time: " << getWorkTime() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
}
