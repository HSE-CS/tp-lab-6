// Copyright 2021 Egor Trukhin
#include "Manager.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>

//===================================================================================
// ProjectManager

ProjectManager::ProjectManager(uint32_t id, const std::string& name,
                               const std::vector<project_t*>& projects)
    : Employee(id, name) {
  this->projects.clear();
  this->projects.push_back(projects[0]);
  this->position = position_t::PROJECTMANAGER;
}

uint32_t ProjectManager::calcProAdditions() { return 0; }

uint32_t ProjectManager::calcBudgetPart(double part, uint32_t budget) {
  if (part < 0.0 || part > 1.0)
    throw std::runtime_error("Part of project budget is uncorrect!");
  return static_cast<uint32_t>(part * static_cast<double>(budget));
}

uint32_t ProjectManager::calcHeads() {
  uint32_t result = 0;
  for (auto project : this->projects) result += project->staff_size * 2500;
  return result;
}

void ProjectManager::calc() {
  this->payment = calcBudgetPart(0.1, this->projects[0]->budget) + calcHeads();
}

void ProjectManager::printInfo() {
  Employee::printId();
  if (this->position == position_t::PROJECTMANAGER)
    std::cout << std::setw(20) << "Project manager";
  else
    std::cout << std::setw(20) << "Senior manager";
  std::cout << " |";
  std::cout << std::setw(10) << " |";
  Employee::printInfo();
  for (auto project : this->projects) std::cout << " " << project->name;
  std::cout << std::endl;
}

std::vector<project_t*>& ProjectManager::getProjects() {
  return this->projects;
}

//===================================================================================
// SeniorManager

SeniorManager::SeniorManager(uint32_t id, const std::string& name,
                             const std::vector<project_t*>& projects)
    : ProjectManager(id, name, projects) {
  for (size_t i = 1; i < projects.size(); i++)
    this->projects.push_back(projects[i]);
  this->position = position_t::SENIORMANAGER;
}

void SeniorManager::calc() {
  uint32_t projectsBudget = 0;
  for (auto project : this->projects)
    projectsBudget += calcBudgetPart(0.25, project->budget);
  this->payment = projectsBudget + calcHeads();
}
