// Copyright 2021 soda
#include "Interfaces.h"

#include "Employee.h"
#include "Manager.h"
#include <iostream>
#include <sstream>


ProjectManager::ProjectManager() {
    std::string name = "";
    this->setId(0);
    this->setName(name);
    this->setWorkTime(0);
    this->setPosition(0);
    this->projects = new std::vector<Project*>;
    this->setPayment(0);
}

ProjectManager::ProjectManager(size_t id, std::string name, size_t worktime,
    size_t position, Project* proj) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->projects = new std::vector<Project*>;
    this->setProject(proj);
    proj->hireWorker(this);
    this->setPayment(this->calc());
}

size_t ProjectManager::calc() {
    return (this->calcHeads() + this->calcBugetParts());
}

void ProjectManager::setProject(Project* proj) {
    this->projects->push_back(proj);
}

size_t ProjectManager::calcBugetParts() {
    size_t part = 0;
    for (auto index : *projects) {
       part += index->getPart();
    }
    return (part);
}

size_t ProjectManager::NumOfProjects() {
    return (this->projects->size());
}

std::stringbuf ProjectManager::getProjectNames() {
    std::stringbuf stat;
    std::ostream stream(&stat);
    for (auto& project : *projects) {
        stream << ' ' << project->getName() << ' ';
    }
    return stat;
}

Project* ProjectManager::getProject(size_t index) {
     return (this->projects->at(index));
}

size_t ProjectManager::calcHeads() {
    size_t pay = 0;
    for (auto& project : *projects) {
        pay += project->getNumWorker() * 5000;
     }
    return pay;
}

std::vector<Project*>* ProjectManager::getProjects() {
     return this->projects;
}

std::string ProjectManager::getProjectName() {
    std::string all = { "" };
    for (auto& project : *projects) {
        all += ' ' + project->getName() + ' ';
    }
    return all;
}

void ProjectManager::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nWorktime = "
        << this->getWorktime() << "; Project: "
        << "\"" << this->getProjectName() << "\""
        << ", Final payment = " << this->getPayment() << std::endl;
}

SeniorManager::SeniorManager(size_t id, std::string name, size_t worktime,
    size_t position, std::vector<Project*>* proje) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    for (auto index : *proje) {
        this->setProject(index);
        index->hireWorker(this);
    }
    this->setPayment(this->calc());
}

size_t SeniorManager::calc() {
    return (this->calcHeads() + this->calcBugetParts());
}

void SeniorManager::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nWorktime = "
        << this->getWorktime() << "; Projects: "
        << "\"" << this->getProjectName() << "\""
        << "; Final payment = " << this->getPayment() << " from " <<
        this->NumOfProjects() << " project;" << std::endl;
}
