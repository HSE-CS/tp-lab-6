// Copyright 2021 Shirokov Alexander
#include "Engineer.h"

Engineer::Engineer(int id, int salaryPerHour, std::string name,
  Position position, Project* project, float part)
  : Personal(id, salaryPerHour, std::move(name), position),
  project{ project }, partition{ part } {}

int Engineer::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * budget);
}

void Engineer::calc() {
  this->payment += calcBase(salaryPerHour, this->workTime) +
  calcBudgetPart(partition, project->getBudget());
}

Programmer::Programmer(int id, int salaryPerHour, std::string name,
Position position, Project* project, float part)
: Engineer(id, salaryPerHour, std::move(name), position, project, part) {}

int Programmer::calcProAdditions() {
  return 1000;
}

void Programmer::calc() {
  this->setPayment(
  this->getPayment() + calcBase(salaryPerHour, this->getWorkTime()) +
  calcBudgetPart(partition, project->getBudget()) + calcProAdditions());
}

Tester::Tester(int id, int salaryPerHour, std::string name, Position position,
Project* project, float part)
: Engineer(id, salaryPerHour, std::move(name), position, project, part) {}

int Tester::calcProAdditions() {
  return 500;
}

void Tester::calc() {
  this->setPayment(
  this->getPayment() + calcBase(salaryPerHour, this->getWorkTime()) +
  calcBudgetPart(partition, project->getBudget()) + calcProAdditions());
}

TeamLeader::TeamLeader(int id, int salaryPerHour, std::string name, 
Position position, Project* project, float part)
: Programmer(id, salaryPerHour, std::move(name), position, project, part) {}

int TeamLeader::calcHeads() {
  return 5000;
}

void TeamLeader::calc() {
  this->setPayment(calcBase(salaryPerHour, this->getWorkTime()) +
  calcBudgetPart(partition, project->getBudget()) +
  calcProAdditions() + calcHeads());
}
