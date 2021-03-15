// Copyright [2020] <Olesya Nikolaeva>

#include "Engineer.h"

void Engineer::calc() {
    payment = salary * worktime + calcBudgetPart() + calcProAdditions();
}

void Engineer::printInfo() {
    std::cout << "ID: " << ID << "\nName: " << name <<
    "\nPosition: " << position << "\nWork time: " <<
    worktime << "\nPayment: " << payment << "\nSalary: "
    << salary << "\nProject: " << currentproject->returnName()
    << std::endl;
}

int Engineer::calcProAdditions() {
    return 0;
}

int Engineer::calcBudgetPart() {
    return currentproject->returnBudget() / 10;
}

Project* Engineer::returnProject() {
    return currentproject;
}

int Programmer::calcProAdditions() {
    if (hourspercode < 30) {
        return 1000;
    }
    return 0;
}

void Programmer::spendHours(int number) {
    hourspercode = number;
}

int Tester::calcProAdditions() {
    if (errorsfound > 30) {
        return 1000;
    }
    return 0;
}

void Tester::errors(int number) {
    errorsfound = number;
}

void TeamLeader::calc() {
    payment = calcBudgetPart() + calcBase(salary, worktime)
    + ((calcHeads() - 1) * 100);
}


int TeamLeader::calcHeads() {
    return returnProject()->returnPeoplesNumber();
}

void TeamLeader::printInfo() {
    std::cout << "ID: " << ID << "\nName: " << name <<
    "\nPosition: " << position << "\nWork time: " <<
    worktime << "\nPayment: " << payment << "\nSalary: " << salary <<
    "\nProject: " << currentproject->returnName() << std::endl;
}
