// Copyright 2021 dash
#include "Engineer.h"
#include <string>
#include <iostream>

Engineer::Engineer(int id,
    std::string name,
    Position position,
    int worktime,
    int salary,
    int payment,
    Project* project) : Personal(id,
        name,
        position,
        worktime,
        payment,
        salary), project(project) {
}

Programmer::Programmer(int id,
    std::string name,
    Position position,
    int worktime,
    int salary,
    int payment,
    Project* project)
    : Engineer(id,
        name,
        position,
        worktime,
        payment,
        salary,
        project) {

}

Tester::Tester(int id,
    std::string name,
    Position position,
    int worktime,
    int salary,
    int payment,
    Project* project)
    : Engineer(id,
        name,
        position,
        worktime,
        payment,
        salary,
        project) {

}

TeamLeader::TeamLeader(int id,
    std::string name,
    Position position,
    int worktime,
    int salary,
    int payment,
    Project* project)
    : Programmer(id = 0,
        name =  "",
        position,
        worktime = 0,
        payment = 0,
        salary = 0,
        project = nullptr) {

}

int Engineer::calcBudgetPart(double part, int budget) {
    return static_cast<int>(part * budget);
}

void Engineer::calc() {
    payment = calcBase(salary, worktime) + calcBudgetPart(0.1, project->budget);
}

int Engineer::calcBonus() {
    if (this->worktime > 6 * 20)
        return 10 * (this->worktime - 6 * 20);
    return 0;
}

int Engineer::calcProAdditions() {
    return 1000;
}

void Engineer::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}

int Programmer::calcProAdditions() {
    return 1000;  
}

void Programmer::calc() {
    payment = calcBase(salary, worktime) + calcBudgetPart(0.1, project->budget);
}

int Programmer::calcBonus() {
    if (this->worktime > 6 * 20)
        return 10 * (this->worktime - 6 * 20);
    return 0;
}

void Programmer::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}

void Programmer::add_Bonus() {
    bonus = 1;
}

int Programmer::get_bonus() {
    return bonus;
}

int Tester::calcProAdditions() {
    return 1000;
}

void Tester::calc() {
    payment = calcBase(salary, worktime) + calcProAdditions();
}

void Tester::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}

int TeamLeader::calcHeads() {
    return 1000;
}

int Tester::calcBonus() {
    if (this->worktime > 6 * 20)
        return 10 * (this->worktime - 6 * 20);
    return 0;
}

void TeamLeader::calc() {
    int payment = calcBase(salary, worktime) + calcBudgetPart(0.1, project->budget) + calcHeads();
}

void TeamLeader::print_Info() {
    std::cout << get_Name() + " " + std::to_string(get_Id());
}