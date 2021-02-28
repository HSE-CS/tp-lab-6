//  Copyright 2021 Nikita Naumov

#include "TeamLeader.h"

TeamLeader::TeamLeader(unsigned int id, const std::string& name) : Programmer(id, name) {
    this->id = id;
    this->name = std::move(name);
    setPosition(6);  //  set TL position
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}

unsigned TeamLeader::calcHeads() {
    if (this->linkToProject) {
        return ((this->linkToProject)->getNumberOfMembers() * 1759 / 2);
    } else {
        return 0;
    }
}
void TeamLeader::calc() {
    this->payment = calcBase(this->salaryPerHour, this->worktime) + calcHeads() + calcProAdditions() + calcBudgetPart();
}
void TeamLeader::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " << convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Salary per hour " << this->salaryPerHour << std::endl;
    if (this->linkToProject) {
        std::cout << "Number of subordinates " << this->linkToProject->getNumberOfMembers() << std::endl;
    } else {
        std::cout << "Number of subordinates " << 0 << std::endl;
    }
    std::cout << "Current payment " << this->payment << std::endl;
    std::cout << "Info about related project " << std::endl;
    if (this->linkToProject) {
        std::cout << "Project ID " << this->linkToProject->getProjectID() << std::endl;
    } else {
        std::cout << "No related project " << std::endl;
    }
}