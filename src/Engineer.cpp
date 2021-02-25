// Copyright 2021 by Bodrov Egor

#include "Engineer.h"

Engineer::Engineer(int id, int salaryPerHour, std::string name,
                   std::string pos, Project* project, float part)
    : Personal(id, salaryPerHour, std::move(name), std::move(pos)),
      project{project},
      partition{part} {}

int Engineer::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * budget);
}

void Engineer::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(salaryPerHour, this->getWorkTime()) +
                   calcBudgetPart(partition, project->getBudget()));
}

Programmer::Programmer(int id, int salaryPerHour, std::string name,
                       std::string pos, Project* project, float part)
    : Engineer(id, salaryPerHour, std::move(name), std::move(pos), project,
               part) {}

int Programmer::calcProAdditions() {
  if (partition >= 0.2) {
    return static_cast<int>(calcBudgetPart(partition,
                            project->getBudget()) / 5);
  } else {
    return 0;
  }
}

void Programmer::calc() {
  this->setPayment(
      this->getPayment() + calcBase(salaryPerHour, this->getWorkTime()) +
      calcBudgetPart(partition, project->getBudget()) + calcProAdditions());
}

Tester::Tester(int id, int salaryPerHour, std::string name, Project* project,
               float part)
    : Engineer(id, salaryPerHour, std::move(name), "Tester", project, part) {}

int Tester::calcProAdditions() {
  if (partition >= 0.4) {
    return static_cast<int>(calcBudgetPart(partition,
                            project->getBudget()) / 5);
  } else {
    return 0;
  }
}

void Tester::calc() {
  this->setPayment(
      this->getPayment() + calcBase(salaryPerHour, this->getWorkTime()) +
      calcBudgetPart(partition, project->getBudget()) + calcProAdditions());
}

TeamLeader::TeamLeader(int id, int salaryPerHour, std::string name,
                       Project* project, float part)
    : Programmer(id, salaryPerHour, std::move(name), "TeamLeader", project,
                 part) {}

int TeamLeader::calcHeads() { return 5000; }

void TeamLeader::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(salaryPerHour, this->getWorkTime()) +
                   calcBudgetPart(partition, project->getBudget()) +
                   calcProAdditions() + calcHeads());
}
