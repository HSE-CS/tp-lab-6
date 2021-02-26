// Copyright 2021 Smirnov Grigory
#include "Manager.h"

int ProjectManager::getSubbordinates() {
  return subordinates;
}

int ProjectManager::calcHeads() {
  return getSubbordinates() * 1000;
}

void ProjectManager::calc() {
  setPayment(50000 + calcHeads());
}

void SeniorManager::calc() {
  setPayment(90000 + calcHeads());
}

void ProjectManager::printInfo() {
  std::cout << getName() + " " + std::to_string(getId())
    + " " + std::to_string(getPayment());
}

void SeniorManager::addProject(Project* p) {
  projects.push_back(p);
}

int calcBudgetPart(float part, int budget) {
  return part * budget;
}

int calcProAdditions() {
  return 500 * getSubbordinates();
}