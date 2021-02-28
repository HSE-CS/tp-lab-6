// Copyright 2021 dmitrycvetkov2000
#include "Engineer.h"

#include <cmath>
#include <iostream>
#include <string>

Engineer::Engineer(int id,
    const std::string& name,
    int salary,
    Position position,
    Project* project,
    float part) : Personal(id, name, position, salary), project(project),
    part(part) {
}

int Engineer::calcBonus() const {
    return 0;
}

int Engineer::calcBudget(float part) const {
    return 0;
}

int Engineer::calcProAdditions() const {
    return std::floor(static_cast<float>(project->budget) * 0.1);
}

void Engineer::calc() {
    payment = calcBase() + calcProAdditions();
}

void Engineer::printInfo() const {
    std::cout << "Engineer " << name << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Base payment: " << calcBase() << std::endl;
    std::cout << "Project payment: " << calcBudget(part) << std::endl;
    std::cout << "Bonus: " << calcProAdditions() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}

Programmer::Programmer(int id,
    const std::string& name,
    int salary,
    Project* project,
    float part) : Engineer(id, name, salary,
        Position::Programmer, project, part) {
}

int Programmer::calcBonus() const {
    return calcBase() * 0.05;
}

int Programmer::calcBudget(float part) const {
    return project->budget * part;
}

void Programmer::calc() {
    payment = calcBase() + calcBudget(part) + calcBonus();
}

void Programmer::printInfo() const {
    std::cout << "Programmer " << name << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Base payment: " << calcBase() << std::endl;
    std::cout << "Project payment: " << calcBudget(part) << std::endl;
    std::cout << "Bonus: " << calcBonus() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}

TeamLeader::TeamLeader(int id,
    const std::string& name,
    int salary,
    Project* project,
    float part) : Programmer(id, name, salary, project, part) {
    position = Position::TeamLeader;
}

int TeamLeader::calcBonus() const {
    return std::floor(project->budget * 0.05);
}

int TeamLeader::calcHeads() const {
    return std::floor(0.07 * project->budget);
}

void TeamLeader::printInfo() const {
    std::cout << "Team leader " << name << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Base payment: " << calcBase() << std::endl;
    std::cout << "Project payment: " << calcBudget(part) << std::endl;
    std::cout << "Head payment: " << calcHeads() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}

Tester::Tester(int id,
    const std::string& name,
    int salary,
    Project* project,
    float part) : Engineer(id, name, salary, Position::Tester, project, part) {
}

int Tester::calcBonus() const {
    return std::floor(0.03 * project->budget);
}

int Tester::calcBudget(float part) const {
    return project->budget * part;
}

void Tester::printInfo() const {
    std::cout << "Tester " << name << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << "Worktime: " << worktime << std::endl;
    std::cout << "Base payment: " << calcBase() << std::endl;
    std::cout << "Project payment: " << calcBudget(part) << std::endl;
    std::cout << "Bonus: " << calcBonus() << std::endl;
    std::cout << "Total payment: " << payment << std::endl;
}
