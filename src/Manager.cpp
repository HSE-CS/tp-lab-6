// Copyright 2021 Galex

#include <iostream>
#include <vector>
#include <string>
#include "../include/Manager.h"

ProjectManager::ProjectManager(int id,
                               std::string name,
                               std::vector<Project *> projects) {
  this->setId(id);
  this->setName(name);
  this->setPayment(0);
  this->setPosition(PROJECT_MANAGER);
  this->setWorkTime(0);
  this->projects = projects;
  for (int i = 0; i < projects.size(); ++i) {
    projects[i]->setNumOfWorkers(projects[i]->getNumOfWorkers() + 1);
  }
}

std::vector<Project *> ProjectManager::getProjects() {
  return this->projects;
}

double ProjectManager::calcHeads() {
  double numOfWorkers = 0;
  for (int i = 0; i < projects.size(); ++i) {
    numOfWorkers += projects[i]->getNumOfWorkers();
  }
  return 1300 * numOfWorkers;
}
void ProjectManager::calc() {
  this->setPayment(this->calcHeads() + this->calcBudgetPart(
      (double)1 / (this->projects[0]->getNumOfWorkers()),
      this->projects[0]->getBudget()));
}
double ProjectManager::calcBudgetPart(double part, int budget) {
  return part * budget;
}
void ProjectManager::printInfo() {
  std::cout << "ID: " << this->getId() <<
            " Name: " << this->getName() <<
            " Work Time: " << this->getWorkTime() <<
            " Position: " << this->getPosition() <<
            " Payment: " << this->getPayment() <<
            " Projects: ";
  for (int i = 0; i < this->getProjects().size(); ++i) {
    std::cout << this->getProjects()[i]->getId() << " ";
  }
  std::cout << "\n";
}
void ProjectManager::calcProAdditions() {
}

SeniorManager::SeniorManager(int id,
                             std::string name,
                             std::vector<Project *> projects)
: ProjectManager(id, name, projects) {
  this->setPosition(SENIOR_MANAGER);
}
void SeniorManager::calc() {
  double budgetsParts = 0;
  for (int i = 0; i < this->getProjects().size(); ++i) {
    budgetsParts += this->calcBudgetPart(
        (double)1 / (this->getProjects()[i]->getNumOfWorkers()),
        this->getProjects()[i]->getBudget());
  }
  this->setPayment(this->calcHeads() + budgetsParts);
}
