// Copyright 2021 BekusovMikhail

#include "Engineer.h"

void Engineer::calc() {
    this->payment = this->workTime * this->salary +
                    this->calcBudgetPart(static_cast<float>(0.05),
                                       project->getBudget());
}

int Engineer::calcBudgetPart(float part, int budget) {
    return static_cast<int>(part * static_cast<float>(budget));
}

int Engineer::calcBonus() {
    return 0;
}

Project *Engineer::getProject() {
    return this->project;
}

Tester::Tester(std::string id, std::string name,
               Position position, int salary, Project *project) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->salary = salary;
    this->project = project;
    this->payment = 0;
}

int Tester::calcProAdditions() {
    this->payment += 2000;
    return 2000;
}

Programmer::Programmer(std::string id, std::string name,
                       Position position, int salary, Project *project) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->salary = salary;
    this->project = project;
    this->payment = 0;
}

int Programmer::calcProAdditions() {
    this->payment += 2500;
    return 2500;
}

TeamLeader::TeamLeader(std::string id, std::string name, Position position,
                       int salary, Project *project) :
                       Programmer(id, name, position, salary, project) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->salary = salary;
    this->project = project;
    this->payment = 0;
}

void TeamLeader::calc() {
    this->payment += calcHeads();
    Engineer::calc();
}

int TeamLeader::calcHeads() {
    this->payment = 6000;
    return 6000;
}
