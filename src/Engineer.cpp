// Copyright 2020 Konina Tatiana
#include "Engineer.h"
#include "Project.h"
int programmer_bonus = 6;
int tester_bonus = 7;

Engineer::Engineer(unsigned int id, std::string name,
  int worktime, double salary, int position, Project*pr)
  :Personal(id, name, worktime, salary, position) {
  this->project = pr;
}
int Engineer::calcBudgetPart() {
  if (project) {
    float part = 1.0 / project->getWorkers();
    return  part * (*project).getBudget();
  } else {
    return 0;
  }
}

int Engineer::calcProAdditions(int bonus) {
  return bonus * this->salary;
}

void Engineer::calc() {
  this->payment = calcBudgetPart() + calcBase();
}

void Engineer::setProject(Project*project) {
  this->project = project;
}

void Engineer::printInfo() {
  std::cout << this->name << " " << this->position << std::endl;
  std::cout << "Current payment = " << this->payment << std::endl;
  std::cout << "Current work time = " << this->worktime << std::endl;
  if (project) {
    std::cout << "Current Project - " << project->getTitle() << std::endl;
  }
}

Programmer::Programmer(unsigned int id, std::string name,
  int worktime, double salary, int position, Project* pr)
  : Engineer(id, name, worktime, salary, position, pr) {
  this->bonus = programmer_bonus;
}
void Programmer::calc() {
  this->payment = calcBudgetPart() + calcBase() +
    calcProAdditions(this->bonus);
}



Tester::Tester(unsigned int id, std::string name,
  int worktime, double salary, int position, Project* pr)
  : Engineer(id, name, worktime, salary, position,  pr) {
  this->bonus = tester_bonus;
}
void Tester::calc() {
  this->payment = calcBudgetPart() + calcBase() +
    calcProAdditions(this->bonus);
}



TeamLeader::TeamLeader(unsigned int id, std::string name,
  int worktime, double salary, int position, Project* pr)
  : Programmer(id, name, worktime, salary, position, pr) {}

int TeamLeader::calcHeads() {
  if (project) {
    return project->getWorkers();
  } else {
    return 0;
  }
}
void TeamLeader::calc() {
  this->payment = calcBudgetPart() + calcBase() + calcBonus(calcHeads());
}



