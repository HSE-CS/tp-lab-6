// Copyright 2021 Andrey Bakurskii

#include "Manager.h"

int ProjectManager::calc() {
  int base = getPayment() * getWorktime();
  int bonusProjects = 0;
  for (size_t i = 0; i < projects.size(); i++) {
    bonusProjects += calcBudgetPart(0.1, projects[i]->budget);
  }

  int addititions = calcProAdditions();
  int heads = calcHeads();

  return base + bonusProjects + addititions + heads;
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  int budgetpart = static_cast<int>(part * budget);
  return budgetpart;
}

int ProjectManager::calcProAdditions() {
  int p = getPayment();
  int wt = getWorktime();

  if (wt > 40) {
    int salary = static_cast<int>(p * wt * 0.35);
    return salary;
  }
  return 0;
}

int ProjectManager::calcHeads() {
  int p = getPayment();
  int wt = getWorktime();
  int res = static_cast<int>(p * 0.2 * wt);
  return res;
}

void ProjectManager::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  for (size_t i = 0; i < projects.size(); i++) {
    info += "Project: id - " + std::to_string(projects[i]->id) + " budget - " +
            std::to_string(projects[i]->budget) + "\n";
  }
  std::cout << info;
}

Project* ProjectManager::getProject(int id) {
  for (size_t i = 0; i < projects.size(); i++) {
    if (projects[i]->id == id) {
      return projects[i];
    }
  }
  return nullptr;
}

int SeniorManager::calc() {
  return getPayment() * getWorktime() +
         getProject(this->id_project)->budget * 0.02;
}

void SeniorManager::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  info += "Project: id - " +
          std::to_string(getProject(this->id_project)->id) +
          " budget - " + std::to_string(getProject(this->id_project)->budget) +
          "\n";
  std::cout << info;
}
