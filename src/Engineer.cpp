//  Copyright 2021 Nikita Naumov
#include "Engineer.h"

Engineer::Engineer(unsigned int id, const std::string& name) : Personal(id, name){
    this->id = id;
    this->name = name;
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
void Engineer::setProject(Project* link) {
    this->linkToProject = link;
}
unsigned Engineer::calcBudgetPart() {
    return ((this->linkToProject)->getProjectBudget()/this->linkToProject->getNumberOfMembers());
}
void Engineer::calc() {
    this->payment = calcBudgetPart() + calcBase(this->getSalaryPerHour(), this->worktime);
}