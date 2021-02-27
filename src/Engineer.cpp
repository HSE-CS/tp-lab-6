// Copyright [2021] <Roman Balayan>

#include "Engineer.h"

Engineer::Engineer(unsigned int id,
                   std::string name,
                   Position position,
                   unsigned int worktime,
                   unsigned int payment,
                   unsigned int salary,
                   std::shared_ptr<Project> project)
    : Personal(id, name, position, worktime, payment, salary)
    , project(project) {
}

int Engineer::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * budget);
}

void Engineer::calc() {
    this->payment = calcBase(this->salary, this->worktime) +
                    calcBudgetPart(0.1, project->budget);
}

Programmer::Programmer(unsigned int id,
    std::string name,
    Position position,
    unsigned int worktime,
    unsigned int payment,
    unsigned int salary,
    std::shared_ptr<Project> project)
    : Engineer(id,
                name,
                Position::Programmer,
                worktime,
                payment,
                salary,
                project) {
}

int Programmer::calcProAdditions() {
    return 500;  // No instructions so just 500
}

void Programmer::printInfo() {
    std::cout << "Programmer info:\n";
}

Tester::Tester(unsigned int id,
    std::string name,
    Position position,
    unsigned int worktime,
    unsigned int payment,
    unsigned int salary,
    std::shared_ptr<Project> project)
    : Engineer(id,
                name,
                Position::Tester,
                worktime,
                payment,
                salary,
                project) {
}

int Tester::calcProAdditions() {
    return 200;  // No instructions so just 200
}

void Tester::printInfo() {
    std::cout << "Tester info:\n";
}

int TeamLeader::calcHeads() {
    return 1000;  // No instructions so just 1000
}

void TeamLeader::calc() {
    this->payment = calcBase(this->salary, this->worktime) +
                    calcBudgetPart(0.1, project->budget) +
                    calcHeads();
}
