// Copyright 2020 Konina Tatiana
#include <iostream>
#include "Manager.h"

ProjectManager::ProjectManager(unsigned int id, std::string name,
  int worktime, int position,double salary, std::vector <Project *> pr)
  : Employee(id, name, worktime, position) {
  this->salary = salary;
  this->projects = pr;
}

int ProjectManager::calcHeads() {
  int total_workers = 0;
  for (auto pr : projects) {
    if (pr) {
      total_workers += pr->getWorkers();
    }
  }
  return total_workers;
}
void ProjectManager::calc() {
  int bonus = 0;
  for (auto pr : projects) {
    if (pr && pr->getState()) {
      bonus += 1;
    }
  }
  this->payment = calcHeads() * this->salary + calcBudgetPart() +
    calcProAdditions(bonus);
}

void ProjectManager::printInfo() {
  std::cout << this->name << " " << this->position << std::endl;

  for (auto pr : projects) {
    if (pr) {
      std::cout << pr->getTitle() << " number of workers = "
        << pr->getWorkers() << std::endl;
    }
  }

  std::cout << "Payment = " << this->payment << std::endl;
}

int ProjectManager::calcBudgetPart() {
  if (projects.size() >= 1) {
    float part = float(1) / projects[0]->getWorkers();
    return  part * (*projects[0]).getBudget();
  } else {
    return 0;
  }
}
int ProjectManager::calcProAdditions(int bonus) {
  return bonus * this->salary;
}

void SeniorManager::calc() {
  int total_sum = 0;
  for (auto pr : projects) {
    float part = float(1) / pr->getWorkers();
    total_sum += pr->getBudget() * part;
  }
  this->payment = total_sum;
}
SeniorManager::SeniorManager (unsigned int id, std::string name,
  int worktime, int position, double salary, std::vector <Project*> pr)
  : ProjectManager(id, name, worktime, position,salary, pr) {}




