// Copyright 2021 Igumnova Natasha
#include "Engineer.h"
#include <fstream>
#include <string>
#include <cmath>

int Engineer::calcBudgetPart(float part, int budget) {
    return part * budget;
}

int Engineer::calc() {
    return Personal::calc();
}

void Engineer::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(getSalary())
        + "\nProject id " + std::to_string(getProject().id)
        + "\nProject budget " + std::to_string(getProject().budget);
    std::cout << res << std::endl;
}

Project Engineer::getProject() {
    return project;
}

int Tester::calcAdditions() {
    return Personal::calcBonus();
}

int Tester::calcBonus() {
    return Personal::calcBonus();
}
int Tester::calc() {
    return Engineer::calc() + calcBonus() + calcProAdditions();
}

int Tester::calcProAdditions() {
    return Personal::calcBonus();
}

void Tester::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(getSalary())
        + "\nProject id " + std::to_string(getProject().id)
        + "\nProject budget " + std::to_string(getProject().budget);
    std::cout << res << std::endl;
}

int Programmer::calcBonus() {
    return Engineer::calcBonus();
}
int Programmer::calc() {
    return Engineer::calc() + calcBonus() + calcProAdditions();
}

void Programmer::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(getSalary())
        + "\nProject id " + std::to_string(getProject().id)
        + "\nProject budget " + std::to_string(getProject().budget);
    std::cout << res << std::endl;
}

int Programmer::calcProAdditions() {
    return Personal::calcBonus();
}

int TeamLeader::calcHeads() {
    return static_cast<int>(getProject().budget * 0.1);
}
int TeamLeader::calc() {
    return Engineer::calc() + calcBonus() + calcProAdditions();
}

int TeamLeader::calcBonus() {
    return Engineer::calcBonus();
}

void TeamLeader::printInfo() {
    std::string res;
    res = "id " + std::to_string(getId())
        + "\nname " + getName() + "\nposition " + getPosition()
        + "\npayment " + std::to_string(getPayment())
        + "\nsalary " + std::to_string(getSalary())
        + "\nProject id " + std::to_string(getProject().id)
        + "\nProject budget " + std::to_string(getProject().budget);
    std::cout << res << std::endl;
}
