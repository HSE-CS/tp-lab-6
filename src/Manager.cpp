// Copyright 2021 mkhorosh

#include "Manager.h"
#include <iostream>

int ProjectManager::calcHeads() {
  return static_cast<int> (this->projects[0].budget * 0.01);
}
int ProjectManager::calcBudgetPart(float part, int budget) {
  return static_cast<int> (part * budget);
}
int ProjectManager::calcProAdditions() {
  return 1000;
}
void ProjectManager::calc() {
  payment = getPayment() * getWorkTime() + calcProAdditions();
}
void ProjectManager::printInfo() {
  std::cout << "id: " << getId() << "\n"
            << "name: " << getName() << "\nPosition: " << getPosition()
            << "\nWorktime: " << getWorkTime() << "\nPayment: " << getPayment()
            << std::endl;
}

