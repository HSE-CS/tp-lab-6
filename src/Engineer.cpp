// Copyright 2021 valvarl

#include "../include/Engineer.h"

#include <utility>
#include <sstream>
#include <iostream>
#include <Factory.h>

int Engineer::calcBudgetPart(float part, int budget) {
    return project->budget / static_cast<int>(part);
}

Engineer::
Engineer(int id, const std::string &name, Position position, int salary,
         Project *_project, float part) : Personal(id, name, position, salary),
         project(_project), part(part) {}

void Engineer::printInfo() {
    std::stringbuf str;
    std::ostream stream(&str);
    stream << "Id: " << id << "\nName: " << name << "\nPosition: " <<
    getPosition() << "\nProject: " << project->name << "\nWork time: "
    << workTime << "\nSalary: " << salary << "\nPayment: " << payment << "\n";
    std::cout << str.str() << std::endl;
}

int Tester::calcProAdditions() {
    return calcBase(salary, workTime) / 10;
}

void Tester::calc() {
    payment = calcBase(salary, workTime) +
              calcBudgetPart(part, project->budget) + calcProAdditions();
}

Tester::
Tester(int id, const std::string &name, Position position, int salary,
       Project *project, float part) :
       Engineer(id, name, position, salary, project, part) {}

int Programmer::calcProAdditions() {
    return calcBase(salary, workTime) / 10;
}

void Programmer::calc() {
    payment = calcBase(salary, workTime) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
}

Programmer::
Programmer(int id, const std::string &name, Position position, int salary,
           Project *project, float part) : Engineer(id, name, position, salary,
                                                    project, part) {}

int TeamLeader::calcHeads() {
    return 150;
}

void TeamLeader::calc() {
    payment = calcBase(salary, workTime) + calcHeads() +
              calcBudgetPart(part, project->budget) + calcProAdditions();
}

TeamLeader::
TeamLeader(int id, const std::string &name, Position position, int salary,
           Project *project, float part) : Programmer(id, name, position,
                                                      salary, project, part) {}
