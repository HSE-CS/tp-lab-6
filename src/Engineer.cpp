// Copyright 2021 Khoroshavina Ekaterina
#include "Engineer.h"

// class Engineer

Project* Engineer::getProject() {
    return project;
}

void Engineer::setProject(Project* project) {
    this->project = project;
}

double Engineer::getSalary() {
    return calc();
}

double Engineer::calc() {
    setSalary(calcBase(getPayment(), getWorktime()) + calcBonus());
    return calcBase(getPayment(), getWorktime()) + calcBonus();
}

double Engineer::calcBonus() {
    if (getWorktime() > 40) {
        return (getWorktime() * (getPayment() * 1.5));
    } else {
        return 0.0;
    }
}

double Engineer::calcBase(double payment, int time) {
    return Personal::calcBase(payment, time);
}

double Engineer::calcBudgetPart(double part, double budget) {
    return part * budget;
}

double Engineer::calcProAdditions() {
    return calcBonus();
}

void Engineer::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Project - Id: " << project->getId() <<
        " Budget: " << project->getBudget() << std::endl;
    std::cout << "==============" << std::endl;
}

// class Programmer

void Programmer::setProject(Project* project) {
    Engineer::setProject(project);
}

double Programmer::getSalary() {
    return calc();
}

double Programmer::calc() {
    double result = calcBase(getPayment(), getWorktime()) + calcBonus() +
        calcProAdditions() +
        calcBudgetPart(0.04, getProject()->getBudget());
    setSalary(result);
    return result;
}

double Programmer::calcBonus() {
    return Engineer::calcBonus();
}

double Programmer::calcBase(double payment, int time) {
    return Engineer::calcBase(payment, time);
}

double Programmer::calcBudgetPart(double part, double budget) {
    return Engineer::calcBudgetPart(part, budget);
}

double Programmer::calcProAdditions() {
    return Engineer::calcProAdditions();
}

void Programmer::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Project - Id: " << getProject()->getId() <<
        " Budget: " << getProject()->getBudget() << std::endl;
    std::cout << "==============" << std::endl;
}

// class Tester

void Tester::setProject(Project* project) {
    Engineer::setProject(project);
}

void Tester::setMistakes(int num) {
    this->mistakes_counter = num;
}

double Tester::getSalary() {
    return calc();
}

double Tester::calc() {
    double result = calcBase(getPayment(), getWorktime()) + calcBonus() +
        calcProAdditions() +
        calcBudgetPart(0.03, getProject()->getBudget());
    setSalary(result);
    return result;
}

double Tester::calcBonus() {
    if (mistakes_counter > 10) {
        return (getWorktime() * (getPayment() * 1.3));
    } else {
        return 0.0;
    }
}

double Tester::calcBase(double payment, int time) {
    return Engineer::calcBase(payment, time);
}

double Tester::calcBudgetPart(double part, double budget) {
    return Engineer::calcBudgetPart(part, budget);
}

double Tester::calcProAdditions() {
    return Engineer::calcProAdditions();
}

void Tester::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Number of mictakes: " << mistakes_counter << std::endl;
    std::cout << "Project - Id: " << getProject()->getId() <<
        " Budget: " << getProject()->getBudget() << std::endl;
    std::cout << "==============" << std::endl;
}

// class TeamLeader

void TeamLeader::setProject(Project* project) {
    Engineer::setProject(project);
}

double TeamLeader::getSalary() {
    return calc();
}

double TeamLeader::calc() {
    double result = calcBase(getPayment(), getWorktime()) + calcBonus() +
        calcProAdditions() +
        calcBudgetPart(0.05, getProject()->getBudget());
    setSalary(result);
    return result;
}

double TeamLeader::calcBonus() {
    if (getWorktime() > 40) {
        return (getWorktime() * (getPayment() * 1.6));
    } else {
        return 0.0;
    }
}

double TeamLeader::calcBase(double payment, int time) {
    return Programmer::calcBase(payment, time);
}

double TeamLeader::calcBudgetPart(double part, double budget) {
    return Programmer::calcBudgetPart(part, budget);
}

double TeamLeader::calcProAdditions() {
    return TeamLeader::calcBonus();
}

double TeamLeader::calcHeads() {
    double bonus = 0.0025;
    return getProject()->getBudget() * bonus;
}

void TeamLeader::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Project - Id: " << getProject()->getId() <<
        " Budget: " << getProject()->getBudget() << std::endl;
    std::cout << "==============" << std::endl;
}
