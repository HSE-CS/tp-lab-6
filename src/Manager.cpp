//  Copyright Baklanov 2021
#include "Manager.h"

int ProjectManager::calcHeads() {
    return 200000;
}

void ProjectManager::calc() {
    this->payment = this->calcHeads();
}

void ProjectManager::printinfo() {
    std::cout << this->id << "." << this->name << "\n"
        "position: " << "\t" << this->position << "\n"
        "worktime: " << "\t" << this->worktime << "\n"
        "payment: " << "\t" << this->payment << "\n" << std::endl;
}

void SeniorManager::printinfo() {
    std::cout << this->id << "." << this->name << "\n"
        "projectID:" << "\t" << this->project->id << "\n"
        "position: " << "\t" << this->position << "\n"
        "worktime: " << "\t" << this->worktime << "\n"
        "payment: " << "\t" << this->payment << "\n" << std::endl;
}

void SeniorManager::calc() {
    this->payment = this->calcHeads() * 0.8;
}

int ProjectManager::calcBudjetPart(float part, int budget) {
    int paymentForProjects = 0;
    for (Project* p : Projects) {
        paymentForProjects += p->budjet * p->partForManagers;
    }
    return paymentForProjects;
}

int SeniorManager::calcBudjetPart(float part, int budget) {
    return part * budget;
}

int ProjectManager::calcProAdditions() {
    return rand() % 1000 + 500;
}

int SeniorManager::calcProAdditions() {
    return rand() % 1000 + 500;
}
