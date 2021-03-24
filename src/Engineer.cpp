// Copyright 2021 Shatilov Victor

#include "Engineer.h"

#include <utility>
#include <iostream>

Engineer::Engineer( int id, std::string name,
                    int workTime, int salary, Positions position, Project *p)
: Personal(id, std::move(name), workTime, salary, position), project(p) {}

int Engineer::calcBudgetPart() {
    return static_cast<int>((1.0f / project->getCountWorkers()) * project->getBudget());
}

void Engineer::printInfo() {
    std::cout << id << ". Name: " << name << std::endl;
    std::cout << "Position: " << positions[position] << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    if (project)
        std::cout << "Working on : " << project->getName() << "with id " << project->id << " already: " << workTime
                  << " Payment: " << payment << std::endl;
}

int Engineer::calcProAdditions() { return  bonus * salary; };
int Engineer::calc() {
    return payment = calcBudgetPart() + calcBase() + calcProAdditions();
}

Programmer::Programmer( int id, std::string name,
                        int wt, int salary, Positions position, Project *project)
        : Engineer(id, std::move(name), wt, salary, position, project) {}


Tester::Tester( int id, std::string name,
                int wt, int salary, Positions position, Project* project)
        : Engineer(id, std::move(name), wt, salary, position, project) {}

TeamLeader::TeamLeader( int id, std::string name,
                        int wt, int salary, Positions position, Project *project)
        : Programmer(id, std::move(name), wt, salary, position, project) {}

        int TeamLeader::calcHeads() { return project->getCountWorkers() * 200; }

        int TeamLeader::calc() {
    return payment = calcBase() +
              calcBudgetPart() +
              calcHeads();
}