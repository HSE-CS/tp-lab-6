// Copyright 2021 Nikolaev Ivan

#include "Engineer.h"
#include <iostream>

void Engineer::calc() {
    setPayment(calcBase(this->salary, getWorktime()) + calcBonus() +
        calcProAdditions() + calcBudgetPart(0.01, project->budget));
}

void Engineer::printInfo() {
    std::cout << "id: " << getId() << " \tname: " << getName() <<
        "\nPosition: " << positionToString() << " \tProject: " <<
        project->id << "\nWorktime: " << worktime << " \tPayment: " << payment
        << std::endl;
    std::cout << "=====================================" << std::endl;
}

int Engineer::calcBudgetPart(float part, int budget) {
    return float(part * budget);
}

int Engineer::calcBonus() {
    if (getWorktime() > 40) {
        return calcBase(this->salary, this->getWorktime()) * 0.1;
    }
}

int Engineer::calcProAdditions() {
    return 0;
}

Engineer::Engineer(int id, std::string name, Position position,
    int worktime, int salary, Project* project) :
    Personal(id, name, position, worktime, salary) {
    this->project = project;
}

Programmer::Programmer(int id, std::string name, Position position,
    int worktime, int salary, Project* project) : Engineer(id, name, position,
        worktime, salary, project) {
}

void Programmer::giveBonus() {
    this->bonus = true;
}

bool Programmer::getBonus() {
    return bonus;
}

int Programmer::calcProAdditions() {
    if (bonus) {
        return 30000;
    } else {
        return 0;
    }
}

int Tester::calcProAdditions() {
    return getMistakes() * 1000;
}

void Tester::addMistakes(int mistakes) {
    this->mistakes += mistakes;
}

int Tester::getMistakes() {
    return mistakes;
}

Tester::Tester(int id, std::string name, Position position,
    int worktime, int salary, Project* project) : Engineer(id, name, position,
        worktime, salary, project) {
}

void TeamLeader::calc() {
    setPayment(calcBase(this->salary, getWorktime()) + calcBonus() +
        calcBudgetPart(0.02, project->budget) + calcHeads());
}
int TeamLeader::calcHeads() {
    return 40000;
}

TeamLeader::TeamLeader(int id, std::string name, Position position,
    int worktime, int salary, Project* project) : Programmer(id, name,
        position, worktime, salary, project) {
}
