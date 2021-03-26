#include "Engineer.h"

void Engineer::calc() {
    payment = calcBudgetPart(0.1) + calcProAdditions() + calcBonus() + calcBase();
}

Engineer::Engineer(unsigned int id, std::string name, unsigned int salary) : Personal(id, name, salary), project(project) {
}

unsigned int Programmer::calcBudgetPart(float part) {
    return part * project.getBudget();
}

unsigned int Programmer::calcProAdditions() {
    if(workTime > 160) {
        return 10000;
    }
}

unsigned int Programmer::calcBonus() {
    if(workTime > 200) {
        return 10000;
    }
}

Programmer::Programmer(unsigned int id, std::string name, unsigned int salary, Project project) : Engineer(id, name,
                                                                                                           salary) {
    this->position = programmer;
    this->project = project;
}

Programmer::Programmer(unsigned int id, std::string name, unsigned int salary) : Engineer(id, name, salary) {
    this->position = programmer;
}

void Programmer::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Programmer" << std::endl
              << "Work time: " << workTime << std::endl << "Payment: " << payment << std::endl << "Salary: " << salary
              << std::endl << "Project ID: " << project.getId() << std::endl;
}

Tester::Tester(unsigned int id, std::string name, unsigned int salary, Project project) : Engineer(id, name, salary) {
    this->position = tester;
    this->project = project;
}

Tester::Tester(unsigned int id, std::string name, unsigned int salary) : Engineer(id, name, salary) {
    this->position = tester;
}

unsigned int Tester::calcBudgetPart(float part) {
    return part * project.getBudget();
}

unsigned int Tester::calcProAdditions() {
    if(workTime > 160) {
        return 10000;
    }
}

unsigned int Tester::calcBonus() {
    if(workTime > 200) {
        return 10000;
    }
}

void Tester::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Programmer" << std::endl
              << "Work time: " << workTime << std::endl << "Payment: " << payment << std::endl << "Salary: " << salary
              << std::endl << "Project ID: " << project.getId() << std::endl;
}

TeamLeader::TeamLeader(unsigned int id, std::string name, unsigned int salary, Project project) : Programmer(id, name,
                                                                                                             salary,
                                                                                                             project) {
    this->position = teamLeader;
}

TeamLeader::TeamLeader(unsigned int id, std::string name, unsigned int salary) : Programmer(id, name, salary) {
    this->position = teamLeader;
}

unsigned int TeamLeader::calcHeads() {
    return project.getPeople() * 1000;
}

unsigned int TeamLeader::calcBudgetPart(float part) {
    return part * project.getBudget();
}

unsigned int TeamLeader::calcProAdditions() {
    if(workTime > 160) {
        return 15000;
    }
}

unsigned int TeamLeader::calcBonus() {
    if(workTime > 200) {
        return 15000;
    }
}

void TeamLeader::calc() {
    payment = calcBudgetPart(0.2) + calcProAdditions() + calcBonus() + calcBase();
}

void TeamLeader::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Programmer" << std::endl
              << "Work time: " << workTime << std::endl << "Payment: " << payment << std::endl << "Salary: " << salary
              << std::endl << "Project ID: " << project.getId() << std::endl;
}
