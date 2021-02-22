// Copyright 2021 VadMack



#include <Engineer.h>

#include <utility>

int Engineer::calcBudgetPart(float part, int budget) {
  return (int) (part * budget);
}

void Engineer::calc() {
  this->payment = calcBase(this->salary, this->workTime)
      + calcBudgetPart(0.10f, project->GetBudget());
}

int Engineer::calcBonus() {
}

int Tester::calcProAdditions() {
  this->payment += 5000;
  return 5000;
}

Tester::Tester(std::string id,
               std::string name,
               POSITION position,
               int salary,
               Project *project) {
  this->id = std::move(id);
  this->name = std::move(name);
  this->position = position;
  this->salary = salary;
  this->project = project;
}

int Programmer::calcProAdditions() {
  this->payment += 6000;
  return 6000;
}

Programmer::Programmer(std::string id,
                       std::string name,
                       POSITION position,
                       int salary,
                       Project *project) {
  this->id = std::move(id);
  this->name = std::move(name);
  this->position = position;
  this->salary = salary;
  this->project = project;
}

int TeamLeader::calcHeads() {
  this->payment += 10000;
  return 10000;
}

void TeamLeader::calc() {
  Engineer::calc();
  this->payment += calcHeads();
}

TeamLeader::TeamLeader(std::string id, std::string name, POSITION position, int salary, Project *project) : Programmer(
    id,
    name,
    position,
    salary,
    project) {}
