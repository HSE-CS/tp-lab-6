#include "Manager.h"

#include <iostream>

#define PER_HEAD 10
#define PRO_ADDITIONS 15

void ProjectManager::printInfo() {
  this->Employee::printInfo();
  std::cout << "PRO_ADDITIONS: " << calcProAdditions() << std::endl;
}
uint32_t ProjectManager::calcHeads() { return projects->staff * PER_HEAD; }

uint32_t ProjectManager::calcBudgetPart(float part, uint32_t budget) {
  return (uint32_t)(part * (float)budget);
}

uint32_t ProjectManager::calcProAdditions() { return PRO_ADDITIONS; }

void ProjectManager::calc() {
  payment = calcHeads() +
            calcBudgetPart(1.0 / (float)projects->staff, projects->budget) +
            calcProAdditions();
}

void SeniorManager::calc() {
  uint32_t sum = 0;
  for (int i = 0; i < num_projects; ++i) {
    Project* current_project = projects + i;
    sum += calcBudgetPart(1.0 / (float)current_project->staff,
                          current_project->budget);
  }
  payment = calcHeads() + sum + calcProAdditions();
}
