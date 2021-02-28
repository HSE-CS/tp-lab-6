// Copyright 2021 me

#include "../include/Manager.h"

int ProjectManager::calcHeads() {
  return 10 * (proj->getTesters() + proj->getWorkers());
}

int ProjectManager::calcProAdditions() { return getWorkTime() * 100; }

int ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void ProjectManager::calc() {
  setPayment(calcHeads() + calcBudgetPart(0.2, proj->getBudget()) +
             calcProAdditions());
}

void ProjectManager::printInfo() {
  std::cout << "Employee:\n";
  std::cout << "\tName: " << getName() << "\n";
  std::cout << "\tId: " << getId() << "\n";
  std::cout << "\tPosition: " << getPosition() << "\n";
  std::cout << "\tWork time: " << getWorkTime() << "\n";
  std::cout << "\tProject ID: " << proj->getProjectID() << "\n";
  std::cout << "\tProject budget: " << proj->getBudget() << "\n";
  std::cout << "\tBudget part: " << 0.2 << "\n";
  std::cout << "\tPayment: " << getPayment() << "\n";
}

void SeniorManager::addProject(Project* project) {
  progectList.push_back(project);
}

void SeniorManager::calc() { int pay = 0;
  for (auto proj : progectList) {
    pay += (proj->getTesters() + proj->getWorkers()) * 10 +
           calcBudgetPart(0.1, proj->getBudget());
  }
  setPayment(pay + calcProAdditions());
}

void SeniorManager::printInfo() {
  std::cout << "Employee:\n";
  std::cout << "\tName: " << getName() << "\n";
  std::cout << "\tId: " << getId() << "\n";
  std::cout << "\tPosition: " << getPosition() << "\n";
  std::cout << "\tWork time: " << getWorkTime() << "\n";
  std::cout << "\tBudget part: " << 0.1 << "\n";
  std::cout << "\tProjects ID: ";
  for (auto pr : progectList) {
    std::cout << pr->getProjectID() << " ";
  }
  std::cout << "\n\tBudget part: " << 0.1 << "\n";
  std::cout << "\tPayment: " << getPayment() << "\n";
}
