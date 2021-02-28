// Copyright 27.02.21 DenisKabanov

#include "Manager.h"

int ProjectManager::getSub() {
  return this->bossOf;
}

Project* ProjectManager::getProject() {
  return this->projects;
}

void ProjectManager::addSub(int count) {
  this->bossOf += count;
}

int ProjectManager::calcHeads(int salaryForSub = 5000) {
  int salaryForHeading = getSub() * salaryForSub;
  return salaryForHeading;
}

int ProjectManager::calcProAdditions(int addCount = 0, int addPrice = 0) {
  int proAdd = addCount * addPrice;
  return proAdd;
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  auto budgetAddition = part * budget;
  return budgetAddition;
}

void ProjectManager::calc() {
  setPayment(this->passivesalary + calcBudgetPart(0.2, getProject()->budget) +
             calcHeads(5000));
}

void ProjectManager::printInfo() {
  std::cout << "Name: " << getName() << " ID: " << getID()
            << " Position: " << getPos() << " Number of subs: " << getSub()
            << "\nName of projects: " << getProject()->id
            << " Salary: " << getPayment() << std::endl;
}

int SeniorManager::getSub() {
  return this->bossOf;
}

void SeniorManager::addSub(int count) {
  this->bossOf +=  count;
}

int SeniorManager::calcHeads(int salaryForSub = 5000) {
  int salaryForHeading = getSub() * salaryForSub;
  return salaryForHeading;
}

int SeniorManager::calcProAdditions(int addCount = 0, int addPrice = 500) {
  int proAdd = addPrice * projects.size();
  return proAdd;
}

void SeniorManager::calc() {
  setPayment(this->passivesalary + calcHeads() + calcProAdditions(0, 500));
}

void SeniorManager::printInfo() {
  std::cout << "Name: " << getName() << " ID: " << getID()
            << " Position: " << getPos() << " Number of subs: " << getSub()
            << "\nName of projects: " << getProject()->id
            << " Salary: " << getPayment() << std::endl;
}
