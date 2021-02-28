// Copyright 2021 Sozinov Kirill

#include "Factory.h"

int Project::getTeamSize() {
    return team_size;
}

int Project::getBudget() {
    return budget;
}

int Project::getId() {
    return id;
}

std::vector<Employee*> StaffFactory::makeStaff(std::string _projectsFile,
    std::string _employeesFile) {
    
}
