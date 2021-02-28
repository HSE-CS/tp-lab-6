// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#include "Engineer.h"

#include <utility>

Engineer::Engineer(int id, std::string name,
                   int workTime, int salary, Positions position, Project *p)
    : Personal(id, std::move(name), workTime, salary, position) {
  this->project = p;
}
int Engineer::calcBudgetPart() {
  if (project) {
    return (int) (1.0 / project->getAmountOfWorkers())
        * (*project).getBudget();
  } else {
    return 0;
  }
}

int Programmer::calcProAdditions(int bonus) {
  return bonus * this->salary;
}
int Tester::calcProAdditions(int bonus) {
  return bonus * this->salary;
}

int Engineer::calc() {
  return this->payment = calcBudgetPart() + calcBase(salary, workTime);
}
const char* enum_print2[] = { "cleaner",
                             "driver",
                             "tester",
                             "programmer",
                             "team_leader",
                             "project_manager",
                             "senior_manager"} ;
void Engineer::printInfo() {
  std::cout << enum_print2[this->position] << std::endl;
  std::cout << this->name << std::endl;
  std::cout << "Work time = " << this->workTime << std::endl;
  std::cout << "Payment = " << this->payment << std::endl;
}

Programmer::Programmer(int id, std::string name,
                       int workTime, int salary, Positions position, Project *p)
    : Engineer(id, std::move(name), workTime, salary, position, p) {
}
int Programmer::calc() {
  return this->payment = calcProAdditions() + calcBudgetPart() +
      calcBase(salary, workTime);
}

Tester::Tester(int id, std::string name,
               int workTime, int salary, Positions position, Project *pr)
    : Engineer(id, std::move(name), workTime, salary, position, pr) {
}
int Tester::calc() {
  return this->payment = calcProAdditions() + calcBudgetPart() +
      calcBase(salary, workTime);
}

TeamLeader::TeamLeader(int id, std::string name,
                       int workTime, int salary, Positions position, Project *pr)
    : Programmer(id, std::move(name), workTime, salary, position, pr) {}

int TeamLeader::calcHeads() {
  if (project) {
    return project->getAmountOfWorkers();
  } else {
    return 0;
  }
}

int TeamLeader::calc() {
  return this->payment = calcBase(salary, workTime)
      + calcBonus(calcHeads()) + calcBudgetPart();
}



