// Copyright 2021 Dev-will-work
#include "Manager.h"

ProjectManager::ProjectManager(Project* projects,
  std::string fio, Position pos) {
  this->name = fio;
  this->position = pos;
  this->projects = projects;
  this->id = createId();
}

ProjectManager::~ProjectManager() {
  if (this->position != Position::SENIOR_MANAGER &&
    this->projects) delete this->projects;
}

void ProjectManager::printInfo() {
  std::cout << "Project Manager "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Project: " << "\n\n";
  std::cout << "Project id: " << this->projects->id << "\n";
  std::cout << "Project budget: " << this->projects->budget << "\n\n";
  std::cout << "Count of subordinates: " << this->subordinates_count << "\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}

int ProjectManager::calcProAdditions() {
  return 0;
}

int ProjectManager::calcHeads() {
  return 500 * this->subordinates_count;
}

Project* ProjectManager::getProject() {
  return this->projects;
}

void ProjectManager::calc() {
  this->payment = this->calcBudgetPart(0.2f, this->projects->budget);
  this->payment += this->calcHeads();
}

SeniorManager::SeniorManager(Project* projects, std::string fio,
  Position pos, size_t project_count)
  : ProjectManager::ProjectManager(projects, fio, pos) {
  this->projects_count = project_count;
}

SeniorManager::~SeniorManager() {
  if (this->projects) delete[] this->projects;
}

void SeniorManager::calc() {
  this->payment = this->calcHeads();
  for (size_t i = 0; i < this->projects_count; i++) {
    this->payment += this->calcBudgetPart(0.1f, this->projects[i].budget);
  }
}

void SeniorManager::printInfo() {
  std::cout << "Senior Manager "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Projects: " << "\n\n";
  for (size_t i = 0; i < this->projects_count; i++) {
    std::cout << "Project id: " << this->projects[i].id << "\n";
    std::cout << "Project budget: " << this->projects[i].budget << "\n\n";
  }
  std::cout << "Count of subordinates: " << this->subordinates_count << "\n\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
}










