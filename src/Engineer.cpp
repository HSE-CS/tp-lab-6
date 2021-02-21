//
// Created by Valera on 20.02.2021.
//

#include "../include/Engineer.h"

#include <utility>

int Engineer::calcBudgetPart(float part, int budget) {
    return 0;
}

Engineer::
Engineer(int id, const std::string &name, Position position, int salary,
         Project *project, float part) : Personal(id, name, position, salary),
         project(project), part(part) {}

int Tester::calcProAdditions() {
    return 0;
}

void Tester::calc() {

}

Tester::
Tester(int id, const std::string &name, Position position, int salary,
       Project *project, float part) :
       Engineer(id, name, position, salary, project, part) {}

int Programmer::calcProAdditions() {
    return 0;
}

void Programmer::calc() {

}

Programmer::
Programmer(int id, const std::string &name, Position position, int salary,
           Project *project, float part) : Engineer(id, name, position, salary,
                                                    project, part) {}

int TeamLeader::calcHeads() {
    return 0;
}

void TeamLeader::calc() {
    Programmer::calc();
}

TeamLeader::
TeamLeader(int id, const std::string &name, Position position, int salary,
           Project *project, float part) : Programmer(id, name, position,
                                                      salary, project, part) {}
