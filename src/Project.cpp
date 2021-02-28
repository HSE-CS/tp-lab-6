//  Copyright 2021 Nikita Naumov
#include "Project.h"

Project::Project(int projectID, int projectBudget) {
    this->projectID = projectID;
    this->projectBudget = projectBudget;
    this->numberOfMembers = 0;
}
int Project::getNumberOfMembers() {
    return this->numberOfMembers;
}
int Project::getProjectBudget() {
    return this->projectBudget;
}

