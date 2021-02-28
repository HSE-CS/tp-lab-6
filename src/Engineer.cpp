// Copyright 2021 MalininDmitry
#include <iostream>
#include "Engineer.h"
Engineer::Engineer(unsigned int id, std::string name,
         std::string position, unsigned int payment,
         Project* project, float part) :
         Personal(id, name, position, 0, payment), project(project),
         part(part) {}

Tester::Tester(unsigned int id, std::string name,
        std::string position, unsigned int payment,
        Project* project, float part) :
        Engineer(id, name, position, payment, project, part) {}

Programmer::Programmer(unsigned int id, std::string name,
        std::string position, unsigned int payment,
        Project* project, float part) :
        Engineer(id, name, position, payment, project, part) {}

TeamLeader::TeamLeader(unsigned int id, std::string name,
        std::string position, unsigned int payment,
        Project* project, float part) :
        Engineer(id, name, position, payment, project, part) {}

int Engineer::calcBudgetPart(float part, int budget) {
    return budget / static_cast<int>(part);
}

void Engineer::printInfo() {
    std::cout << "Information : " << std::endl;
    std::cout << "id : " << this->id << std::endl;
    std::cout << "name : " << this->name << std::endl;
    std::cout << "project id : " << project->id << std::endl;
    std::cout << "project budget part : " <<
    Engineer::calcBudgetPart(part,  project->budget) << std::endl;
    std::cout << "position : " << this->position << std::endl;
    std::cout << "worktime : " << this->worktime << std::endl;
    std::cout << "salary : " << this->salary << std::endl;
    std::cout << "payment : " << payment << std::endl;
}

int Tester::calcProAdditions() {
    return (calcBase(this->salary, this->worktime) / 15);
}

void Tester::calc() {
    payment = calcBase(salary, worktime) +
    calcBudgetPart(part, project->budget) + calcProAdditions();
}

int Programmer::calcProAdditions() {
    return calcBase(this->salary, this->worktime) / 10;
}

void Programmer::calc() {
    payment = calcBase(salary, worktime) +
    calcBudgetPart(part, project->budget) + calcProAdditions();
}

int TeamLeader::calcProAdditions() {
    return (calcBase(this->salary, this->worktime) / 5);
}

void TeamLeader::calc() {
    payment = calcBase(salary, worktime) +
    calcBudgetPart(part, project->budget) + calcProAdditions();
}

int TeamLeader::calcHeads() {
    return 200;
}
