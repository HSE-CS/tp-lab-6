// Copyright 2021 Sozinov Kirill

#include "Engineer.h"

Engineer::Engineer(int _id, std::string _name, std::string _position, int
    _salary, Project _pr) : Personal(_id, _name, _position, _salary),
    project(_pr) {}

float Engineer::calcBudgetPart(float part, int budget) {
    return budget * part;
}

void Engineer::printInfo() {
    std::cout << id << ": " << name << ", position: " <<
        position << ", salary: " << salary << "working in project "
        << project.id << "total payment: " << payment << std::endl;
}

Programmer::Programmer(int _id, std::string _name, std::string _position, int
    _salary, Project _pr) : Engineer(_id, _name, _position, _salary, _pr) {}

int Programmer::calcProAdditions() {
    if (worktime > 6)
        return salary * 2 * (worktime - 6);
}

void Programmer::calc() {
    payment = calcBudgetPart(1 / project.getTeamSize(), project.getBudget())
        + calcProAdditions() + calcBase(salary, worktime);
}

Tester::Tester(int _id, std::string _name, std::string _position, int
    _salary, Project _pr) : Engineer(_id, _name, _position, _salary, _pr) {}

int Tester::calcProAdditions() {
    if (worktime > 7)
        return salary * 2 * (worktime - 7);
}

void Tester::calc() {
    payment = calcBudgetPart(1 / project.getTeamSize(), project.getBudget())
        + calcProAdditions() + calcBase(salary, worktime);
}

TeamLeader::TeamLeader(int _id, std::string _name, std::string _position, int
    _salary, Project _pr) : Programmer(_id, _name, _position, _salary, _pr) {}

int TeamLeader::calcHeads() {
    return salary / 4 * project.getTeamSize();
}

void TeamLeader::calc() {
    payment = calcBudgetPart(1 / project.getTeamSize(), project.getBudget())
        + calcProAdditions() + calcBase(salary, worktime) + calcHeads();
}

void TeamLeader::printInfo() {
    std::cout << id << ": " << name << ", position: " <<
        position << ", salary: " << salary << "leading in project " <<
        project.getId() << "total payment: " << payment << std::endl;
}
