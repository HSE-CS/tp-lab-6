//  Copyright 2021 Nikita Naumov
#include "Engineer.h"

Engineer::Engineer(unsigned int id, const std::string& name) : Personal(id, name){
    this->id = id;
    this->name = std::move(name);
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
unsigned int Engineer::calcBonus() {
    return (this->additionalHours * this->worktime / 2);
}
void Engineer::setProject(Project* link) {
    this->linkToProject = link;
    this->linkToProject->addMember();
}
unsigned Engineer::calcBudgetPart() {
    if (this->linkToProject) {
        return ((this->linkToProject)->getProjectBudget()
        / this->linkToProject->getNumberOfMembers());
    } else {
        return 0;
    }
}
void Engineer::calc() {
    this->payment = calcBudgetPart() + calcBase(this->getSalaryPerHour(),
                                                this->worktime);
}
Project* Engineer::getProjectLink() {
    return this->linkToProject;
}