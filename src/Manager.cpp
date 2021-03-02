// Copyright 2021 Shirokov Alexander
#include "Manager.h"

ProjectManager::ProjectManager(int id, std::string name,
Position position, std::vector<Project*> projects, float part) 
: Employee(id, name, position) {
  this->projects = std::move(projects);
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * static_cast<float>(budget));
}

int ProjectManager::calcProAdditions() {
  return 0;
}

int ProjectManager::calcHeads() {
  return 7500;
}

void ProjectManager::calc() {
  int max = 0;
  for (auto pr : projects) {
    if (pr->getBudget() > max) {
      max = pr->getBudget();
    }
  }
  this->payment = calcHeads() + calcBudgetPart(0.2, max);
}

void ProjectManager::printInfo() {
  std::cout << this->id << " " << this->name << " "
  << static_cast<std::underlying_type<Position>::type>(this->position) << " "
  << this->payment << " " << this->workTime << "\n" << "Projects";
  for (auto pr : projects) {
      std::cout << pr->getTitle() << " " << pr->getBudget();
  }
}

SeniorManager::SeniorManager(int id, std::string name,
  std::vector<Project*> projects, Position position, float part)
  : ProjectManager(id, std::move(name), position, projects, part) {}

void SeniorManager::calc() {
  int max = 0;
  for (auto pr : projects) {
    if (pr->getBudget() > max) {
      max += pr->getBudget();
    }
  }
  this->setPayment(calcBudgetPart(partition, max / 10) +
  calcProAdditions() + calcHeads());
}
