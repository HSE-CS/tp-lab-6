// Copyright 2021 Stolbov Yaroslav

#include <Manager.h>

unsigned int Project::getId() const {
    return id;
}

int Project::getBudget() const {
    return budget;
}

void Project::setBudget(int budget) {
    this->budget = budget;
}

Project::Project(int id, std::string name) {
    this->id = id;
    this->name = name;
}

unsigned int Project::getNumberOfArticipants() const {
    return numberOfArticipants;
}

void Project::addArticipants() {
    this->numberOfArticipants += 1;
}

const std::string &Project::getName() const {
    return name;
}

void Project::setName(const std::string &name) {
    Project::name = name;
}

ProjectManager::ProjectManager(unsigned int id,
                               std::string name, Position position)
: Employee(id, std::move(name), position) {}

const Project &ProjectManager::getProject() const {
    return project;
}

void ProjectManager::setProject(Project &project) {
    this->project = project;
    project.addArticipants();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return part * budget;
}

int ProjectManager::calcProAdditions() {
    return 0;
}

int ProjectManager::calcHeads() {
    return project.getNumberOfArticipants() * 1000;
}

void ProjectManager::calc() {
    payment = calcBudgetPart(partOfTheProject,
                             project.getBudget()) + calcHeads();
}

float ProjectManager::getPartOfTheProject() const {
    return partOfTheProject;
}

void ProjectManager::setPartOfTheProject(float partOfTheProject) {
    this->partOfTheProject = partOfTheProject;
}

void ProjectManager::printInfo() {
    printPosition();
    std::cout << "ID: " << id << "\nName: "
    << name << "\nNumber of articipants: " <<
              project.getNumberOfArticipants()
              << "\nManagement premium: " << calcHeads() <<
              "\nPart of the project: "
              << partOfTheProject << "\nPayment: " << payment;
}

SeniorManager::SeniorManager(unsigned int id, std::string name, Position position)
: ProjectManager(id, std::move(name), position) {

}

void SeniorManager::addProject(Project &project) {
    projects.emplace_back(project);
}

void SeniorManager::calc() {
    unsigned int generalBudget = 0;
    for (auto &project : projects) {
        payment += project.getNumberOfArticipants() * 1000;
        generalBudget += project.getBudget();
    }
    payment += calcBudgetPart(getPartOfTheProject(), generalBudget);
}

void SeniorManager::printInfo() {
    printPosition();
    std::cout << "ID: " << id << "\nName: " << name <<
              "\nPart of the project: "
              << getPartOfTheProject() << "\nPayment: " << payment;
    std::cout << "\nProjects: ";
    unsigned int generalCount = 0;
    for (auto &project : projects) {
        std::cout << project.getName() << "; ";
        generalCount += project.getNumberOfArticipants();
    }
    std::cout << "\nNumber of articipants: " << generalCount;
}
