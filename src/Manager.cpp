// Copyright 2021 Pavlova D.

#include "../include/Manager.h"

int ProjectManager::calcHeads() {
  int sum = 0;
  for (auto proj : allProjects)
    sum += proj->team * 1000;

  return sum;
}

int ProjectManager::calcBudgetPart(float _part, int _budget) {
  return static_cast<int>(static_cast<float>(_budget) / _part);
}

int ProjectManager::calcProAdditions() { return 50; }

void ProjectManager::calc() {
  payment = calcHeads() + calcBudgetPart(part, allProjects[0]->Budget) +
            calcProAdditions();
}

void ProjectManager::printInfo() {
  std::cout << "id: " << getId() << "\n"
            << "name: " << getName() << "\nPosition: " << getPosition()
            << "\nWorktime: " << worktime << "\nPayment: " << payment
            << std::endl;
}
