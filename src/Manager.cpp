// Copyright 2021 LongaBonga
#include "Manager.h"

int ProjectManager::calcHeads() {
  int sum = 0;
  for (auto p : projects) {
    sum += 5000;
  }
  return sum;
}

int ProjectManager::calc() {
  int sum = 0;
  for (auto p : projects) sum += p->budget;
  payment = calcBudgetPart(part, sum) + calcProAdditions() + calcHeads();
  return payment;
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  return budget * part;
}

int ProjectManager::calcProAdditions() {
  int sum = 0;
  for (auto p : projects) sum += p->budget;
  return calcBudgetPart(part, sum) / 20;
}

void ProjectManager::printInfo() {
  std::cout << "Employee fields: \n";
  std::cout << "\t"
            << "Id: " << getId() << '\n';
  std::cout << "\t"
            << "Name: " << getName() << '\n';
  std::cout << "\t"
            << "Position: " << getPosition() << '\n';
  std::cout << "\t"
            << "Work time: " << getWorktime() << '\n';
  std::cout << "\t"
            << "Projects: \n";
  for (auto p : projects) {
    std::cout << "\t\t" << p->name << "\n";
  }
}
