//  Copyright 2021 Nikita Naumov

#include "TeamLeader.h"

TeamLeader::TeamLeader(unsigned int id, const std::string& name) : Programmer(id, name) {
    this->id = id;
    this->name = name;
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}

unsigned TeamLeader::calcHeads() {
    return ((this->linkToProject)->getNumberOfMembers() * 1759 / 2);
}
void TeamLeader::calc() {
    this->payment = calcBase(this->salaryPerHour, this->worktime) + calcHeads() + calcProAdditions();
}