// Copyright 2020 GHA Test Team
#include "Engineer.h"
#include <iostream>


int Engineer::calcBonus() const {
  return 1500;
}

int Engineer::calcBudgetPart(float part, int budget) const {
  return part * budget;
}

void Engineer::calc() {
  payment = calcBudgetPart(0.1f, project->budget) +
    calcProAdditions() + calcBase(salary, worktime) + calcBonus();
}

void Engineer::printInfo() const {
  Personal::printInfo();
  std::cout << "Project: " << project->id << "  Budget: " <<
    project->budget << std::endl;
}

void Engineer::InitializeByFourParams(int id, std::string name,
  int salary, Project* project) {
  this->id = id;
  this->name = name;
  this->salary = salary;
  this->project = project;
  worktime = payment = 0;
}

Programmer::Programmer() {
  initializeParamsByZero();
  project = nullptr;
  position = Position::PROGRAMMER;
}

Programmer::Programmer(int id, std::string name,
  int salary, Project* project) {
  InitializeByFourParams(id, name, salary, project);
  position = Position::PROGRAMMER;
}

int Programmer::calcProAdditions() const {
  return 1250;
}

Tester::Tester() {
  initializeParamsByZero();
  project = nullptr;
  position = Position::TESTER;
}

Tester::Tester(int id, std::string name, int salary, Project* project) {
  InitializeByFourParams(id, name, salary, project);
  position = Position::TESTER;
}

int Tester::calcProAdditions() const {
  return 1100;
}

TeamLeader::TeamLeader() {
  initializeParamsByZero();
  project = nullptr;
  position = Position::TEAM_LEADER;
}

TeamLeader::TeamLeader(int id, std::string name,
  int salary, Project* project) {
  InitializeByFourParams(id, name, salary, project);
  position = Position::TEAM_LEADER;
}

int TeamLeader::calcHeads() const {
  return 1500 * (project->workers_num - 1);
}

void TeamLeader::calc() {
  Programmer::calc();
  payment += calcHeads();
}
