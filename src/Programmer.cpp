//  Copyright 2021 Nikita Naumov

#include "Programmer.h"

Programmer::Programmer(unsigned int, const std::string&) : Engineer(id, name){
    this->id = id;
    this->name = name;
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
unsigned Programmer::calcProAdditions() {
    return salaryPerHour * worktime / 2;
}
void Programmer::calc() {
    this->payment = calcBudgetPart() + calcProAdditions() + calcBase(this->salaryPerHour, this->worktime);
}