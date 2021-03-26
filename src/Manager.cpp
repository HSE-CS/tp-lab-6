// Copyright 2021 Ziganshin Nikita

#include "Manager.h"

unsigned int Project::getId() const {
    return id;
}

void Project::setId(unsigned int id) {
    Project::id = id;
}

unsigned int Project::getBudget() const {
    return budget;
}

void Project::setBudget(unsigned int budget) {
    Project::budget = budget;
}

unsigned int Project::getPeople() const {
    return people;
}

void Project::setPeople(unsigned int people) {
    Project::people = people;
}

Project::Project(unsigned int id, unsigned int budget) {
    this->id = id;
    this->budget = budget;
}

unsigned int ProjectManager::calcHeads() {
    return project.getPeople() * 1000;
}

void ProjectManager::calc() {
    payment = calcHeads() + calcBudgetPart(0.1) + calcProAdditions();
}

void ProjectManager::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Project Manager" << std::endl
              << "Payment: " << payment << std::endl << "Project ID: " << project.getId() << std::endl
              << "Project budget: " << project.getBudget() << std::endl << "Amount of people on project: "
              << project.getPeople();
}

ProjectManager::ProjectManager(unsigned int id, std::string name, Project project) : project(project) {
    this->id = id;
    this->name = std::move(name);
    this->project = project;
    this->position = projectManager;
    this->project.setPeople(this->project.getPeople() + 1);
}

unsigned int ProjectManager::calcBudgetPart(float part) {
    return part * project.getBudget();
}

unsigned int ProjectManager::calcProAdditions() {
    if (workTime > 160) {
        return 10000;
    }
}

const Project &ProjectManager::getProject() const {
    return project;
}

void ProjectManager::setProject(const Project &project) {
    ProjectManager::project = project;
}

unsigned int SeniorManager::calcHeads() {
    int result = 0;
    for (auto &project : projects) {
        result += project.getPeople() * 1000;
    }
    return result;
}

void SeniorManager::calc() {
    payment = calcHeads() + calcProAdditions() + calcBudgetPart(0.15);
}

void SeniorManager::printInfo() {
    std::cout << "ID: " << id << std::endl << "Name: " << name << std::endl << "Position: Senior Manager" << std::endl
              << "Payment: " << payment << std::endl << "Projects IDs: ";
    for (auto &project : projects) {
        std::cout << project.getId() << ' ';
    }
    std::cout << std::endl << "Projects budgets: ";
    for (auto &project : projects) {
        std::cout << project.getBudget() << ' ';
    }
    std::cout << std::endl << "Amount of people on projects: ";
    for (auto &project : projects) {
        std::cout << project.getPeople() << ' ';
    }
}

unsigned int SeniorManager::calcBudgetPart(float part) {
    int result = 0;
    for (auto &project : projects) {
        result = part * project.getBudget();
    }
    return result;
}

SeniorManager::SeniorManager(unsigned int id, const std::string &name, std::vector<Project> projects) : ProjectManager(
        id,
        name,
        project) {
    this->id = id;
    this->name = name;
    this->projects = std::move(projects);
    this->position = seniorManager;
    for(auto & project : this->projects) {
        project.setPeople(project.getPeople() + 1);
    }
}

SeniorManager::SeniorManager(unsigned int id, const std::string &name, Project project) : ProjectManager(id,
                                                                                                         name,
                                                                                                         project) {
    this->id = id;
    this->name = name;
    projects.emplace_back(project);
    projects.back().setPeople(projects.back().getPeople() + 1);
}