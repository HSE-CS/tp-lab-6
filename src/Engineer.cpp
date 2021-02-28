// Copyright 2021 Egor Trukhin
#include "Engineer.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>

//===================================================================================
// Engineer

Engineer::Engineer(uint32_t id, std::string& name, uint32_t salary,
                   project_t* project)
    : Personal(id, name, salary) {
  this->project = project;
}

uint32_t Engineer::calcBudgetPart(double part, uint32_t budget) {
  if (part < 0.0 || part > 1.0)
    throw std::runtime_error("Part of project budget is uncorrect!");
  return static_cast<uint32_t>(part * static_cast<double>(budget));
}

void Engineer::calc() {
  double contribution = 1.0 - (1.0 / log10(this->worktime));
  uint32_t partOfBudget = calcBudgetPart(contribution, this->project->budget);
  this->project->budget -= partOfBudget;
  this->payment = calcBase(this->salary, this->worktime) + partOfBudget +
                  calcProAdditions();
}

void Engineer::printInfo() {
  Employee::printId();
  if (this->position == position_t::PROGRAMMER)
    std::cout << std::setw(16) << "Programmer";
  else if (this->position == position_t::TESTER)
    std::cout << std::setw(16) << "Tester";
  else
    std::cout << std::setw(12) << "Team leader";
  std::cout << " |";
  std::cout << std::setw(5) << std::to_string(this->salary) << " |";
  Employee::printInfo();
  std::cout << " " << this->project->name << std::endl;
}

//===================================================================================
// Programmer

Programmer::Programmer(uint32_t id, std::string& name, uint32_t salary,
                       project_t* project)
    : Engineer(id, name, salary, project) {
  this->position = position_t::PROGRAMMER;
}

uint32_t Programmer::calcProAdditions() {
  bool codeIsBest = (rand() % 2 == 0) ? true : false;
  if (codeIsBest && this->worktime < 25) return sqrt(this->salary);
  return 0;
}

//===================================================================================
// Tester

Tester::Tester(uint32_t id, std::string& name, uint32_t salary,
               project_t* project)
    : Engineer(id, name, salary, project) {
  this->position = position_t::TESTER;
}

uint32_t Tester::calcProAdditions() {
  bool errorsFound = rand() % 100;
  return errorsFound * 10;
}

//===================================================================================
// TeamLeader

TeamLeader::TeamLeader(uint32_t id, std::string& name, uint32_t salary,
                       project_t* project)
    : Programmer(id, name, salary, project) {
  this->position = position_t::TEAMLEADER;
}

uint32_t TeamLeader::calcHeads() {
  return (this->project->staff_size - 1) * 2500;
}

void TeamLeader::calc() {
  this->Engineer::calc();
  this->payment += calcHeads();
}
