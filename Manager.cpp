// Copyright 2021 Schenikova

#include "Manager.h"

unsigned int ProjectManager::calcHeads() {
    return numOfHeads * percent;
}

void ProjectManager::calc() {
    payment = part * projects[0].budget + calcHeads();
}

void ProjectManager::setPercent(int percent) {
  this->percent = percent;  
}

void ProjectManager::setNum(int numOfHeads) {
  this->numOfHeads = numOfHeads;
}

void SeniorManager::calc() {
    for (auto p : projects) {
        payment = part * p.budget;
    }
    payment+=calcHeads();
}
