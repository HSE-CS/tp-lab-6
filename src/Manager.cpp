// Copyright 2021 TimurZaytsev
//

#include "Manager.h"
#include <iostream>
#include <vector>


ProjectManager::ProjectManager(int id, std::string name, std::string pos,
                               std::vector<Project*> projects, float part)
    : Employee(id, std::move(name), std::move(pos)), partition{part} {
  for (auto pr : projects) {
    this->projects.push_back(pr);
  }
}

int ProjectManager::calcPartOfBudget(float part, int budget) {
  return static_cast<int>(part * budget);
}

int ProjectManager::calcPAditions() {
  if (partition >= 0.3) {
    return 5000;
  } else {
    return 0;
  }
}

int ProjectManager::calcHeads() { return 5000; }

void ProjectManager::calc() {
  int max{0};
  for (auto pr : projects) {
    if (pr->getBudget() > max) {
      max = pr->getBudget();
    }
  }
  this->setPayment(this->getPayment() + calcPartOfBudget(partition, max / 2) +
                   calcPAditions() + calcHeads());
}

void ProjectManager::printInfo() {
  std::cout << "Name: " << this->getName() << '\n'
            << "Position: " << this->getPos() << '\n'
            << "Worktime: " << this->getWorkTime() << '\n'
            << "Following projects: ";
  for (auto pr : projects) {
    std::cout << pr->getTitle() << " ";
  }
  std::cout << "\nPayment (with bonuses): " << this->getPayment() << '\n';
}

SeniorManager::SeniorManager(int id, std::string name,
                             std::vector<Project*> projects, float part)
    : ProjectManager(id, std::move(name), "SeniorManager", projects, part) {}

void SeniorManager::calc() {
  int max{0};
  for (auto pr : projects) {
    if (pr->getBudget() > max) {
      max += pr->getBudget();
    }
  }
  this->setPayment(this->getPayment() + calcPartOfBudget(partition, max / 10) +
                   calcPAditions() + calcHeads());
}
