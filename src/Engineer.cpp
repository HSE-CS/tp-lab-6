// Copyright 2021 Stolbov Yaroslav
#include <Manager.h>
#include <Engineer.h>

#include <utility>


Engineer::Engineer(unsigned int id, std::string name,
                   Position position, unsigned int salaryPerHour)
: Personal(id, std::move(name), position, salaryPerHour) {}

const Project &Engineer::getProject() const {
    return project;
}

void Engineer::setProject(const Project &project) {
    this->project = project;
    this->project.addArticipants();
}

int Engineer::calcBudgetPart(float part, int budget) {
    return part * budget;
}

void Engineer::calc() {
    this->payment = calcBase(salaryPerHour, workTime);
    this->payment += calcBudgetPart(partOfTheProject, project.getBudget());
}

int Engineer::calcProAdditions() {
    return 0;
}

float Engineer::getPartOfTheProject() const {
    return partOfTheProject;
}

void Engineer::setPartOfTheProject(float partOfTheProject) {
    Engineer::partOfTheProject = partOfTheProject;
}

int Engineer::calcBonus() {
    return 0;
}

void Engineer::printInfo() {
    std::cout << "ID: " << id << "\nName: "
    << name << "\nWork time: " << workTime << "\nSalary per hour: "
              << salaryPerHour <<
              "\nPart of the project: " << partOfTheProject
              << "\nPayment: " << payment;
}


Tester::Tester(unsigned int id, std::string name,
               Position position,
               unsigned int salaryPerHour)
               : Engineer(id, std::move(name),
                          position, salaryPerHour) {}

int Tester::calcProAdditions() {
    return bonus;
}

void Tester::calc() {
    Engineer::calc();
    payment += calcProAdditions();
}

void Tester::setBonus(unsigned int bonus) {
    Tester::bonus = bonus;
}

Programmer::Programmer(unsigned int id,
                       std::string name, Position position,
                       unsigned int salaryPerHour)
                       : Engineer(id, std::move(name),
                                  position, salaryPerHour) {}

int Programmer::calcProAdditions() {
    return bonus;
}

void Programmer::calc() {
    Engineer::calc();
    payment += calcProAdditions();
}

void Programmer::setBonus(unsigned int bonus) {
    Programmer::bonus = bonus;
}

TeamLeader::TeamLeader(unsigned int id,
                       std::string name,
                       Position position, unsigned int salaryPerHour)
: Programmer(id, std::move(name), position, salaryPerHour) {}

unsigned int TeamLeader::getCountHeadings() const {
    return countHeadings;
}

void TeamLeader::setCountHeadings(unsigned int countHeadings) {
    TeamLeader::countHeadings = countHeadings;
    project.getNumberOfArticipants();
}

int TeamLeader::calcHeads() {
    return countHeadings * 1000;
}

void TeamLeader::calc() {
    Programmer::calc();
    payment += calcHeads();
}

void TeamLeader::printInfo() {
    Engineer::printInfo();
    std::cout << "\nNumber of subordinates: "
    << countHeadings << "\nAllowance: " << calcHeads();
}
