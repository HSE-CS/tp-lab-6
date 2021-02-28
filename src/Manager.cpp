//  Copyright 2021 Nikita Naumov

#include "Manager.h"

ProjectManager::ProjectManager(unsigned int id, const std::string& name) : Employee(id, name) {
    this->id = id;
    this->name = std::move(name);
    this->worktime = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
    setPosition(3);  //  set Manager position
}
void ProjectManager::setProject(Project* link) {
    this->linkToProject = link;
    this->linkToProject->addMember();
}
unsigned ProjectManager::calcHeads() {
    return ((this->linkToProject)->getNumberOfMembers() * 1759 / 4);
}

unsigned ProjectManager::calcBudgetPart() {
    if (this->linkToProject) {
        return ((this->linkToProject)->getProjectBudget() / this->linkToProject->getNumberOfMembers());
    } else {
        return 0;
    }
}
unsigned ProjectManager::calcProAdditions() {
    return (calcHeads() * 4);
}
void ProjectManager::calc() {
    this->payment = calcHeads() + calcBudgetPart() + calcProAdditions();
}

void ProjectManager::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " << convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Current payment " << this->payment << std::endl;
    std::cout << "Info about related project" << std::endl;
    if (this->linkToProject) {
        std::cout << "Project ID " << this->linkToProject->getProjectID() << std::endl;
    } else {
        std::cout << "No related projects " << std::endl;
    }
}

SeniorManager::SeniorManager(unsigned id, std::string name) : ProjectManager(id, name){
    this->id = id;
    this->name = std::move(name);
    this->projects.clear();
    this->worktime = 0;
    setPosition(5);  //  set SeniorManager;
    this->linkToProject = nullptr;
    this->projects.clear();
    this->payment = 0;
}
SeniorManager::~SeniorManager() {
    this->projects.clear();
}

void SeniorManager::setProject(Project* link) {
    (this->projects).push_back(link);
    link->addMember();
}

unsigned SeniorManager::calcHeads() {
    unsigned headsSalary = 0;
    for (size_t i = 0; i < this->projects.size(); ++i) {
        headsSalary += this->projects[i]->getNumberOfMembers() * 1759;
    }
    return headsSalary;
}
void SeniorManager::calc() {
    this->payment = calcHeads() + calcBudgetPart() + calcProAdditions();
}

void SeniorManager::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " << convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Current payment " << this->payment << std::endl;
    std::cout << "Info about related project" << std::endl;
    if (this->projects.size()) {
        for (size_t i = 0; i < this->projects.size(); ++i) {
            std::cout << i + 1 << " project ID " << this->projects[i]->getProjectID() << std::endl;
        }
    } else {
        std::cout << "No related projects" << std::endl;
    }
}