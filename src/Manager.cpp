// Copyright 2020 S. BOR

#include "Manager.h"

unsigned ProjectManager::calcHeads(int numberOfWorkers) {
  return numberOfWorkers * 100;
}

void ProjectManager::printInfo() {
  this->calc();
  std::cout << this->name << " " << this->position << " " << this->payment
  << std::endl;
}

unsigned ProjectManager::calcProAdditions() {
  return 0;
}

unsigned ProjectManager::calcBudgetPart(float part, int budget) {
  return static_cast<unsigned>(part * budget);
}

void ProjectManager::calc() {
  payment = calcHeads(5) + calcBudgetPart(0.1, projects[0].budget);
}

void SeniorManager::clac() {
  payment = 0;
  for(int i = 0; i < numberOfProjects; i++)
    payment += calcBudgetPart(0.1, projects[i].budget);
  payment += calcHeads(numberOfProjects * 5);
}
