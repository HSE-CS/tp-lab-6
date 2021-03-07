// Copyright 2021 TimurZaytsev
//

#include "Engineer.h"

Engineer::Engineer(int id, int HourSalary, std::string name, std::string pos,
                   Project* project, float part)
    : Personal(id, HourSalary, std::move(name), std::move(pos)),
      project{project},
      partition{part} {}

int Engineer::calcPartOfBudget(float part, int budget) {
  return static_cast<int>(part * budget);
}

void Engineer::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(HourSalary, this->getWorkTime()) +
                   calcPartOfBudget(partition, project->getBudget()));
}

Programmer::Programmer(int id, int HourSalary, std::string name,
                       std::string pos, Project* project, float part)
    : Engineer(id, HourSalary, std::move(name), std::move(pos), project,
               part) {}

int Programmer::calcPAditions() {
  if (partition >= 0.2) {
    return static_cast<int>(calcPartOfBudget(partition, project->getBudget()) /
                            5);
  } else {
    return 0;
  }
}

void Programmer::calc() {
  this->setPayment(
      this->getPayment() + calcBase(HourSalary, this->getWorkTime()) +
      calcPartOfBudget(partition, project->getBudget()) + calcPAditions());
}

Tester::Tester(int id, int HourSalary, std::string name, Project* project,
               float part)
    : Engineer(id, HourSalary, std::move(name), "Tester", project, part) {}

int Tester::calcPAditions() {
  if (partition >= 0.4) {
    return static_cast<int>(calcPartOfBudget(partition, project->getBudget()) /
                            5);
  } else {
    return 0;
  }
}

void Tester::calc() {
  this->setPayment(
      this->getPayment() + calcBase(HourSalary, this->getWorkTime()) +
      calcPartOfBudget(partition, project->getBudget()) + calcPAditions());
}

TeamLeader::TeamLeader(int id, int HourSalary, std::string name,
                       Project* project, float part)
    : Programmer(id, HourSalary, std::move(name), "TeamLeader", project,
                 part) {}

int TeamLeader::calcHeads() { return 5000; }

void TeamLeader::calc() {
  this->setPayment(this->getPayment() +
                   calcBase(HourSalary, this->getWorkTime()) +
                   calcPartOfBudget(partition, project->getBudget()) +
                   calcPAditions() + calcHeads());
}
