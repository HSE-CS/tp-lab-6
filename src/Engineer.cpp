//// Copyright 2021 Dmitry Vargin

#include "Engineer.h"

void Engineer::setProject(Project *p) {
    this->project = p;
}

Project * Engineer::getProject() {
    return this->project;
}

int Engineer::calcBudgetPart(float part, int budget) {
    return this->project->getBudget() / part;
}

int Engineer::calc() {
    payment = calcBase(getSalary(), getWorktime()) +
              calcBudgetPart(part, project->getBudget())
              + calcProAdditions();
    return payment;
}

void Engineer::printInfo() {
    std::cout << "ID: " << std::to_string(getId()) << std::endl;
    std::cout << "NAME: " << getName() << std::endl;
    std::cout << "POSITION: " << getPosition() << std::endl;
    std::cout << "WORK TIME: " << this->getWorktime() << std::endl;

    std::cout << "SALARY: " +
                 std::to_string(getSalary()) << std::endl;

    std::cout << "PROJECT:  ID: " +
    std::to_string(this->getProject()->getId()) << std::endl;
}

int Tester::calcProAdditions() {
    return calcBase(this->getSalary(),
                    getWorktime()) / 10;
}

int Programmer::calcProAdditions() {
    return calcBase(getSalary(), getWorktime()) / 10;
}

int TeamLeader::calcHeads() { return 150; }
