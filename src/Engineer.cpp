// Copyright 2021 JGMax

#include <ctime>
#include <iostream>
#include "Engineer.h"

Engineer::Engineer(const int id,
                   const std::string fullName,
                   const int workTime,
                   const Position position,
                   const int salary,
                   Project* project) : Personal(id,
                                                fullName,
                                                workTime,
                                                position,
                                                salary) {
    this->proAdditionK = 0;
    this->project = project;
    if (project) {
        project->addWorker();
    }
}

int Engineer::calcBudgetPart() {
    if (project) {
        return project->getBudget() / project->getWorkers();
    } else {
        return 0;
    }
}

int Engineer::calcProAdditions() {
    return calcBase() * proAdditionK;
}

void Engineer::calc() {
    payment = calcBase() + calcBudgetPart() + calcProAdditions();
}

void Engineer::setProAddition(const double proAddition) {
    proAdditionK = proAddition;
}

void Engineer::printInfo() {
    Personal::printInfo();
    std::cout << "Salary:\t" << salary << std::endl;
    if (project) {
        std::cout << "Project name:\t" << project->getTitle() << std::endl;
    }
}

Programmer::Programmer(const int id,
                       const std::string fullName,
                       const int workTime,
                       const Position position,
                       const int salary,
                       Project *project) : Engineer(id,
                                                    fullName,
                                                    workTime,
                                                    position,
                                                    salary,
                                                    project) {
    setProAddition();
}

void Programmer::setProAddition() {
    if (project && project->getStatus()) {
        Engineer::setProAddition(0.5);
    } else {
        Engineer::setProAddition(0);
    }
}

void Programmer::calc() {
    setProAddition();
    Engineer::calc();
}

Tester::Tester(const int id,
               const std::string fullName,
               const int workTime,
               const Position position,
               const int salary,
               Project *project) : Engineer(id,
                                            fullName,
                                            workTime,
                                            position,
                                            salary,
                                            project) {
    setProAddition();
}

void Tester::setProAddition() {
    if (project && project->getStatus()) {
        srand(time(nullptr));
        Engineer::setProAddition(0.01 * (rand() % 100));
    } else {
        Engineer::setProAddition(0);
    }
}

void Tester::calc() {
    setProAddition();
    Engineer::calc();
}

TeamLeader::TeamLeader(const int id,
                       const std::string fullName,
                       const int workTime,
                       const Position position,
                       const int salary,
                       Project *project) : Programmer(id,
                                                      fullName,
                                                      workTime,
                                                      position,
                                                      salary,
                                                      project) {
    setProAddition();
}

int TeamLeader::calcHeads() {
    if (project) {
        return project->getWorkers() - 1;
    }
    return 0;
}

void TeamLeader::setProAddition() {
    if (project) {
        double addition = 0.01 * calcHeads();
        if (addition > 1) {
            addition = 1;
        }
        Engineer::setProAddition(addition);
    }
    Engineer::setProAddition(0);
}

void TeamLeader::printInfo() {
    Programmer::printInfo();
    std::cout << "Subordinates number:\t" << calcHeads() << std::endl;
}

void TeamLeader::calc() {
    setProAddition();
    Programmer::calc();
}
