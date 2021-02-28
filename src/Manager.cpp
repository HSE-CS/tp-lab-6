//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <string>
#include <vector>
#include "Manager.h"

// * PROJECT MANAGER *

unsigned ProjectManager::calcHeads() {
  unsigned finalResult = 0;
   for (Project* p : this->projects) {
     // 5% of budget per employee
     finalResult += p->getBudget() *
     p->getMembersNum() * 0.05;
   }
  this->payment = finalResult;
  return this->payment;
}

unsigned ProjectManager::calc() {
  unsigned fullBudget = 0;
  for (Project* p : this->projects) {
    fullBudget += p->getBudget();
  }
  this->payment = calcHeads() +
  calcBudgetPart(0.3, fullBudget) +
  calcProAdditions();
  return this->payment;
}

unsigned ProjectManager::calcBudgetPart(float part, unsigned budget) {
  return part * budget;
}

unsigned ProjectManager::calcProAdditions() {
  return 0;
}

void ProjectManager::setProject(Project* project) {
  std::vector<Project*> newProjects = {project};
  this->projects = newProjects;
}

Project* ProjectManager::getProject() {
  return this->projects.back();
}

void ProjectManager::printInfo() {
  std::cout << name << " (id: " << id << ")" << std::endl;
  std::cout << "<Position: " <<
  positionToString(this->position) << "> ";
  std::cout << "Project:" << std::endl;
  projects[0]->printInfo();
  std::cout << "<Payment: " << payment << ">";
  std::cout << std::endl << std::endl;
}

// * SENIOR MANAGER *

void  SeniorManager::setProject(std::vector<Project*> projects) {
  this->projects = projects;
}

Project* SeniorManager::getProject(unsigned index) {
  return this->projects[index];
}

void SeniorManager::printInfo() {
  std::cout << name << " (id: " << id << ")" << std::endl;
  std::cout << "<Position: " <<
  positionToString(this->position) << "> ";
  std::cout << "Projects (" << projects.size() << ") :" << std::endl;
  for (Project* p : projects){
    p->printInfo();
  }
  std::cout << "<Payment: " << payment << ">";
  std::cout << std::endl << std::endl;
}
