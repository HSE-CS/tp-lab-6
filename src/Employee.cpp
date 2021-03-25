// Copyright 2021 Shatilov Victor

#include "Employee.h"

#include <utility>
#include <iostream>

Employee::Employee(int id, std::string name,
                   int workTime, Positions position)
        : id(id), name(std::move(name)),
        workTime(workTime), position(position),
        payment(0) {}

int Employee::calc() {
    return 0;
}

void Employee::printInfo() {
    std::cout << name << " on " << positions[position] << std::endl;
    std::cout << "With payment: " << payment << std::endl;
    std::cout << "Work time: " << workTime <<std::endl;
}

void Employee::setWorkTime(int wt) {
    workTime = wt;
}

Project::Project(int id, std::string name,
                 int budget,  int countWorkers)
        : id(id), name(std::move(name)),
        budget(budget), countWorkers(countWorkers) {}

std::string Project::getName() { return name; }
int Project::getBudget() const { return budget; }
int Project::getCountWorkers() const { return countWorkers; }

