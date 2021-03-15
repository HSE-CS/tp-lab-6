// Copyright [2020] <Olesya Nikolaeva>

#include "Manager.h"


void Project::addPerson() {
    numofPeople++;
}

std::string Project::returnName() {
    return title;
}

int Project::returnPeoplesNumber() {
    return numofPeople;
}

int Project::returnBudget() {
    return budget;
}

int Project::returnTime() {
    return time;
}

void ProjectManager::calc() {
    payment = calcBudgetPart() + (calcHeads() * 100);
}

void ProjectManager::printInfo() {
    std::cout << "ID: " << ID << "\nName: " << name <<
    "\nPosition: " << position << "\nWork time: " <<
    worktime << "\nPayment: " << payment <<
    "\nProjects: " << projectname->returnName() << std::endl;
}

int ProjectManager::calcHeads() {
    return projectname->returnPeoplesNumber();
}

int ProjectManager::calcBudgetPart() {
    return projectname->returnBudget() / 10;
}

void SeniorManager::addProject(Project* newproj) {
    projectnames.push_back(newproj);
}

void SeniorManager::printInfo() {
    std::cout << "ID: " << ID << "\nName: " << name <<
    "\nPosition: " << position << "\nWork time: " <<
    worktime << "\nPayment: " << payment <<
    "\nProjects: " << std::endl;
    for (auto i : projectnames) {
        std::cout << i->returnName() << ", ";
    }
    puts("");
}

void SeniorManager::calc() {
    payment += calcBudgetPart();
    for (auto i : projectnames) {
        payment += i->returnPeoplesNumber() * 100;
    }
}

int SeniorManager::calcBudgetPart() {
    int money = 0;
    for (auto i : projectnames) {
        money += i->returnBudget() / 10;
    }
    return money;
}
