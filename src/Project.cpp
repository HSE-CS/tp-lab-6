//  Copyright 2021 Nikita Naumov
#include "Project.h"

Project::Project(unsigned projectID, unsigned projectBudget) {
    this->projectID = projectID;
    this->projectBudget = projectBudget;
    this->numberOfMembers = 0;
}
unsigned Project::getProjectID() {
    return this->projectID;
}
unsigned Project::getNumberOfMembers() {
    return this->numberOfMembers;
}
unsigned Project::getProjectBudget() {
        return this->projectBudget;
}

void Project::addMember() {
    (this->numberOfMembers)++;
}
void Project::printInfo() {
    std::cout << "Project ID " << this->projectID << std::endl;
    std::cout << "Number of members " << this->numberOfMembers << std::endl;
    std::cout << "Project budget " << this->projectBudget << std::endl;
}