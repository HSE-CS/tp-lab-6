// Copyright 2021 Stifeev Nikita

#include "Engineer.h"

Engineer::Engineer(int id, std::string name, int salary, Project* project) :
    Personal(id, name, salary) {
    this->project = project;
}

int Engineer::calcBudgetPart(float part, int budget) {
    return static_cast<float>(part * static_cast<float>(budget));
}

void Engineer::calc() {
    this->payment = calcBase(this->worktime, this->salary) +
        calcBudgetPart(0.03, project->getBudget()) + calcProAdditions();
}

void Engineer::printInfo() {
    std::cout << "#" << this->id << ". " << posToString(this->position)
        << " " << this->name << " [engineer staff]" << std::endl;
    std::cout << "salary: " << this->salary << "; hours work: "
        << this->worktime << ". earned: " << this->payment
        << std::endl << std::endl;
}

Programmer::Programmer(int id, std::string name, int salary,
    Project* project) :
    Engineer(id, name, salary, project) {
    this->position = PROGRAMMER;
}

int Programmer::calcProAdditions() {
    return 4000;
}

Tester::Tester(int id, std::string name, int salary, Project* project) :
    Engineer(id, name, salary, project) {
    this->position = TESTER;
}

int Tester::calcProAdditions() {
    return 2300;
}

TeamLeader::TeamLeader(int id, std::string name, int salary,
    Project* project) :
    Programmer(id, name, salary, project) {
    this->position = TEAMLEADER;
}

void TeamLeader::calc() {
    this->payment = calcBase(this->worktime, this->salary) +
        calcBudgetPart(0.05, project->getBudget()) + calcHeads();
}

int TeamLeader::calcHeads() {
    return 12000;
}
