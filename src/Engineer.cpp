// Copyright 2021 Bekina Svetlana
#include "Engineer.h"

Engineer::Engineer() {}

int Engineer::calcBugetPart(float part, int budget) {
    return part * budget;
}

void Engineer::calc(){
    setPayment(calcBase(getSalary(), getWorkTime()) + calcBugetPart(0.1, project.budget));
}

void Engineer::printInfo() {
    std::cout << "\nName: " << getName() << "\t" << getId() << std::endl;
    std::cout << "\nSalary: " << getSalary() << "\tWork time: " << getWorkTime() << std::endl;
    std::cout << "\nPayment: " << getPayment() << std::endl;;
    std::cout << "\nProject: " << project.name << "\tBudget: " << project.budget << "\n\n";
}

int Engineer::calcProAdditins() {
    return calcBase(getSalary(), getWorkTime()) * 0.3;
}

Programmer::Programmer() {}

int Programmer::calcProAdditins() {
    return calcBase(getSalary(), getWorkTime()) * 0.5;
}

Tester::Tester() {}

int Tester::calcProAdditins() {
    return calcBase(getSalary(), getWorkTime()) * 0.4;
}

TeamLeader::TeamLeader() {}

int TeamLeader::calcProAdditins() {
    return calcBase(getSalary(), getWorkTime()) * 0.6;
}

int TeamLeader::calcHeads() {
    return 10000;
}
