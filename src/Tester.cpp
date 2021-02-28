//  Copyright 2021 Nikita Naumov

#include "Tester.h"

Tester::Tester(unsigned int id, const std::string& name) : Engineer(id, name) {
    this->id = id;
    this->name = name;
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
unsigned Tester::calcProAdditions() {
    return salaryPerHour * worktime / 2;
}
void Tester::calc() {
    this->payment = calcBudgetPart() + calcProAdditions() + calcBase(this->salaryPerHour, this->worktime);
}