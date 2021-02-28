// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#include <iostream>
#include <utility>
#include "Manager.h"
const char* enum_print3[] = { "cleaner",
                             "driver",
                             "tester",
                             "programmer",
                             "team_leader",
                             "project_manager",
                             "senior_manager"} ;
ProjectManager::ProjectManager(int id, std::string name,
                               int workTime, Positions position, Project *project)
    : Employee(id, std::move(name), workTime, position) {
  this->project = project;
}
void ProjectManager::printInfo() {
  std::cout << enum_print3[this->position] << std::endl;
  std::cout << this->name << std::endl;
  std::cout << "Work time = " << this->workTime << std::endl;
  std::cout << "Payment = " << this->payment << std::endl;
}

int ProjectManager::calcBudgetPart() {
  if (project) {
    return (int) (1.0 / project->getAmountOfWorkers())
        * (*project).getBudget();
  } else {
    return 0;
  }
}
int ProjectManager::calcHeads() {
  return this->project->getAmountOfWorkers();
}
int ProjectManager::calc() {
  return this->payment = calcBudgetPart() +
      calcHeads() * calcProAdditions();
}

int ProjectManager::calcProAdditions(int bonus) {
  return bonus;
}

int SeniorManager::calc() {
  int sum = 0;
  for (auto project_ : projects) {
    sum += (int) (1.0 / project_->getAmountOfWorkers()) * project_->getBudget();
  }
  return this->payment = sum;
}
SeniorManager::SeniorManager(int id, const std::string &name,
                             int workTime, Positions position, std::vector<Project *> p)
    : ProjectManager(id, name, workTime, position, p[0]) {}




