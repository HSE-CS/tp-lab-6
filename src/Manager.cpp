// Copyright 2021 Dumarevskaya
#include "Manager.h"
#include <iostream>

int ProjectManager::calcHeads() {
  return 100;
}

void ProjectManager::calc() {
  payment = calcHeads() + calcBudgetPart(0.3, projects[0]->budget) +
            calcProAdditions();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}

int ProjectManager::calcProAdditions() {
  return 10000;
}

void SeniorManager::calc() {
  for (auto pr : projects) {
    payment += calcBudgetPart(0.4, pr->budget) + calcHeads();
  }
}

void ProjectManager::printInfo() {
  std::cout << "id: " << getId() << "\nname: "
    << getName() << "\nPosition: " << getPosition()
    << "\nWorktime: " << worktime << "\nPayment: " << payment
    << std::endl;
}