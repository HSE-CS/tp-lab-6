// Copyright 2020 Uskova
#include "Project.h"

#include "Engineer.h"

Project::Project(int id, std::string name, int budget) {
  this->id = id;
  this->name = name;
  this->budget = budget;
  this->workers = 0;
}

int Project::getId() {
    return this->id;
}

int Project::getBudget() {
    return this->budget;
}

int Project::getWorkers() {
    return this->workers;
}

void Project::addWorker() {
    this->workers += 1;
}

std::string Project::getName() {
    return this->name;
}

float Project::calcPart() {
    return 1.0 / this->workers;
}
