// Copyright 2020 Polina Lukicheva

#include "Manager.h"
#include "iostream"

int ProjectManager::calcHeads() {
  return 10000;
}

std::vector<Project*> ProjectManager::getProjects() {
  return projects;
}

int ProjectManager::calc() {
  return getPayment() * getWorkTime() + calcProAdditions();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}

int ProjectManager::calcProAdditions() {
  return 10000;
}

void ProjectManager::printInfo() {
  std::cout << "{id=" + std::to_string(getId()) +
    ", name=" + getName() +
    ", position=" + getPosition() +
    ", payment=" + std::to_string(getPayment()) +
    ", salary" + std::to_string(calc());
  for (auto pr : projects) {
    if (pr != nullptr) {
      std::cout << ", project id " + std::to_string(pr->id) +
        ", project budget " + std::to_string(pr->budget) << std::endl;
    } else {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

int SeniorManager::calc() {
  return ProjectManager::calc();
}

void SeniorManager::printInfo() {
  std::cout << "id " + std::to_string(getId()) +
    ", name " + getName() +
    ", position " + getPosition() +
    ", payment " + std::to_string(getPayment()) +
    ", salary " + std::to_string(calc()) << std::endl;
}
