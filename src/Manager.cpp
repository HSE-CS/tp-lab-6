// Copyright 2020 GHA Test Team
#include "Manager.h"
#include <iostream>


void ProjectManager::initializeParamsByZero() {
  id = worktime = payment = projects_num = 0;
  name = "";
  projects = nullptr;
}

void ProjectManager::deleteParams() {
  for (int i = 0; i < projects_num; i++) {
    delete projects[i];
  }
  delete[] projects;
}

ProjectManager::ProjectManager() {
  initializeParamsByZero();
  position = Position::PROJECT_MANAGER;
}

ProjectManager::ProjectManager(int id, std::string name, Project* project) {
  this->id = id;
  this->name = name;
  worktime = payment = 0;
  position = Position::PROJECT_MANAGER;
  projects_num = 1;
  projects = new Project*[projects_num];
  projects[0] = project;
}

ProjectManager::~ProjectManager() {
  deleteParams();
}

void ProjectManager::printInfo() const {
  std::cout << "Position: " << getPosition() << std::endl;
  std::cout << "Id: " << id << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work time: " << worktime << std::endl;
  std::cout << "Payment: " << payment << std::endl;
  std::cout << "Projects: " << std::endl;
  std::cout << "\tProject: " << projects[0]->id << "  Budget: "
    << projects[0]->budget << std::endl;
}

int ProjectManager::calcHeads() const {
  int result = 0;
  for (int i = 0; i < projects_num; i++) {
    result += 1000 * (projects[i]->workers_num - 1);
  }
  return result;
}

int ProjectManager::calcBudgetPart(float part, int budget) const {
  return budget * part;
}

int ProjectManager::calcProAdditions() const {
  return 500;
}

void ProjectManager::calc() {
  payment = calcBudgetPart(0.5f, projects[0]->budget) +
    calcHeads() + calcProAdditions();
}

SeniorManager::SeniorManager() {
  initializeParamsByZero();
  position = Position::SENIOR_MANAGER;
}

SeniorManager::SeniorManager(int id, std::string name,
  Project** projects, int projects_num) {
  this->id = id;
  this->name = name;
  worktime = payment = 0;
  position = Position::SENIOR_MANAGER;
  this->projects_num = projects_num;
  this->projects = projects;
}

SeniorManager::~SeniorManager() {
  deleteParams();
}

int SeniorManager::calcProAdditions() const {
  return 1500;
}

int SeniorManager::calcBudgetPart(float part) const {
  int result = 0;
  for (int i = 0; i < projects_num; i++) {
    result += ProjectManager::calcBudgetPart(part, projects[i]->budget);
  }
  return result;
}

void SeniorManager::calc() {
  payment = calcHeads() + calcProAdditions() + calcBudgetPart(0.2f);
}

void SeniorManager::printInfo() const {
  ProjectManager::printInfo();
  for (int i = 1; i < projects_num; i++) {
    std::cout << "\tProject: " << projects[i]->id <<
      "  Budget: " << projects[i]->budget << std::endl;
  }
}
