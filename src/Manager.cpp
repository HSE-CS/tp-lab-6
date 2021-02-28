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

void ProjectManager::printInfo() {
  std::cout << "\t" << "Id: " << id << '\n';
  std::cout << "\t" << "Name: " << name << '\n';
  std::cout << "\t" << "Position: " << position << '\n';
  std::cout << "\t" << "Work time: " << worktime << '\n';
  std::cout << "\t" << "Payment: " << getPayment() << '\n';
}

float ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void SeniorManager::calc() {
    for (auto p : projects) {
        payment = part * p.budget;
    }
    payment+=calcHeads();
}
