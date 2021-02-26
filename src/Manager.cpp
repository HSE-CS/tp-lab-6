// Copyright 2021 Khoroshavina Ekaterina
#include "Manager.h"

// class Project

Project::Project(int id, double budget) {
    this->id = id;
    this->budget = budget;
}

int Project::getId() {
    return id;
}

double Project::getBudget() {
    return budget;
}

// class ProjectManager

double ProjectManager::calc() {
    return calcProAdditions() + calcHeads() +
        calcBudgetPart(0.2, getProject()->getBudget());
}

double ProjectManager::calcHeads() {
    return getProject()->getBudget() * 0.05;
}

Project* ProjectManager::getProject() {
    return project;
}

void ProjectManager::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Project - Id: " << project->getId() <<
        " Budget: " << project->getBudget() << std::endl;
    std::cout << "==============" << std::endl;
}

double ProjectManager::calcBudgetPart(double part, double budget) {
    return part * budget;
}

double ProjectManager::calcProAdditions() {
    if (getWorktime() > 40) {
        return calcHeads() * 1.5;
    } else {
        return 0.0;
    }
}

// class SeniorManager

double SeniorManager::calc() {
    double temp = 0;
    for (Project* project : projects) {
        temp += calcBudgetPart(0.2, project->getBudget());
    }
    return temp + calcHeads() + calcProAdditions();
}

double SeniorManager::calcBudgetPart(double part, double budget) {
    return part * budget;
}

double SeniorManager::calcProAdditions() {
    if (getWorktime() > 40) {
        return calcHeads() * 2;
    } else {
        return 0.0;
    }
}

double SeniorManager::calcHeads() {
    double result = 0;
    for (Project* project : projects) {
        result += project->getBudget() * 0.1;
    }
    return result;
}

std::string SeniorManager::getProjects() {
    std::string result;
    for (Project* project : projects) {
        result += "Id: " + std::to_string(project->getId()) +
            " Budget: " + std::to_string(project->getBudget())
            + "\n";
    }
    return std::string();
}

void SeniorManager::printInfo() {
    std::cout << "==============" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Position: " << getPosition() << std::endl;
    std::cout << "Payment: " << getPayment() << std::endl;
    std::cout << "Projects: " << getProjects() << std::endl;
    std::cout << "==============" << std::endl;
}
