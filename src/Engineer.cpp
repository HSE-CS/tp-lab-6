//
// Created by Valera on 20.02.2021.
//

#include "../include/Engineer.h"

#include <utility>

int Engineer::calcBudgetPart(float part, int budget) {
    return 0;
}

Engineer::Engineer(int salary, std::vector<Project *> projects, float part) :
Personal(salary), projects(std::move(projects)), part(part) {}

int Tester::calcProAdditions() {
    return 0;
}

void Tester::calc() {

}

int Programmer::calcProAdditions() {
    return 0;
}

void Programmer::calc() {

}

int TeamLeader::calcHeads() {
    return 0;
}

void TeamLeader::calc() {
    Programmer::calc();
}
