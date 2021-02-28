// Copyright 2021
#include "Project.h"

void Project::AddMember() {
    members++;
}

void Project::AddProgrammer() {
    programmers++;
}

int Project::getMember() {
    return members;
}

int Project::getBudget() {
    return budget;
}

int Project::getProgrammers() {
    return programmers;
}

int Project::getId() {
    return id;
}

std::string Project::getName() {
    return name;
}
