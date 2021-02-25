#include "Engineer.h"


int Engineer::calcBudgetPart(double part, int budget) {
    return int(part * budget);
}

Engineer::Engineer(int id, std::string name,
    Position position, std::string project,
    int salary) : Personal(id, name, position, salary) {
    this->project.id = project;
}

void Engineer::calc() {
    this->payment = this->worktime * this->salary
        + calcProAdditions();
}

void Engineer::printInfo() {
    std::cout << "id " << this->Employee::id << std::endl;
    std::cout << "name " << this->name << std::endl;
    std::cout << "position " << "Engineer" << std::endl;
    std::cout << "work time " << this->worktime << std::endl;
    std::cout << "payment " << this->payment << std::endl;
    std::cout << "project " << this->project.id << std::endl;
    std::cout << std::endl;
}
int Engineer::calcProAdditions() {
    return 10000;
}

Tester::Tester(int id, std::string name,
    Position position, std::string project,
    int salary) : Engineer(id, name, position, project, salary) {
    this->project.id = project;
}

void Tester::calc() {
    int count_errors = 14;
    this->payment = this->worktime * this->salary
        + calcProAdditions() + count_errors * 100;
}

void Tester::printInfo() {
    std::cout << "id " << this->Employee::id << std::endl;
    std::cout << "name " << this->name << std::endl;
    std::cout << "position " << "Tester" << std::endl;
    std::cout << "work time " << this->worktime << std::endl;
    std::cout << "payment " << this->payment << std::endl;
    std::cout << "project " << this->project.id << std::endl;
    std::cout << std::endl;
}
int Tester::calcProAdditions() {
    return 10000;
}

Programmer::Programmer(int id, std::string name,
    Position position, std::string project,
    int salary) : Engineer(id, name, position,
        project, salary) {
    this->project.id = project;
    this->project.budget = 500000;
}

void Programmer::calc() {
    this->payment = this->worktime * this->salary +
        calcProAdditions() +
        calcBudgetPart(0.05, this->project.budget);
}

void Programmer::printInfo() {
    std::cout << "id " << this->Employee::id << std::endl;
    std::cout << "name " << this->name << std::endl;
    std::cout << "position " << "Programmer" << std::endl;
    std::cout << "work time " << this->worktime << std::endl;
    std::cout << "payment " << this->payment << std::endl;
    std::cout << "project " << this->project.id << std::endl;
    std::cout << std::endl;
}

int Programmer::calcProAdditions() {
    return 23000;
}

TeamLead::TeamLead(int id, std::string name,
    Position position, std::string project,
    int salary) : Programmer(id, name, position,
        project, salary) {
    this->project.id = project;
    this->project.budget = 1000000;
}

int TeamLead::calcProAdditions() {
    return 20000;
}

void TeamLead::calc() {
    this->payment = this->worktime * this->salary
        + calcProAdditions() +
        calcBudgetPart(0.1, this->project.budget)
        + calcHeads();
}

void TeamLead::printInfo() {
    std::cout << "id " << this->Employee::id << std::endl;
    std::cout << "name " << this->name << std::endl;
    std::cout << "position " << "Team Lead" << std::endl;
    std::cout << "work time " << this->worktime << std::endl;
    std::cout << "payment " << this->payment << std::endl;
    std::cout << "project " << this->project.id << std::endl;
    std::cout << std::endl;
}

int TeamLead::calcHeads() {
    return 5000;
}
