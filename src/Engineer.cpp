// Copyright 2021 Dev-will-work
#include "Engineer.h"

Engineer::Engineer() {
}

Engineer::~Engineer() {
}

int Engineer::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void Engineer::calc() {
  this->payment = calcBase(this->salary, this->worktime);
  this->payment += calcBudgetPart(0.05f, this->project.budget);
  this->payment += calcProAdditions();
}

Programmer::Programmer(Project project, int salary, std::string fio,
  Position pos) {
  this->salary = salary;
  this->name = fio;
  this->position = pos;
  this->project = project;
  this->id = createId();
}

Programmer::~Programmer() {
}

int Programmer::calcProAdditions() {
  return 2000 * worktime;
}

void Programmer::printInfo() {
  std::cout << "Programmer "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Project: " << "\n\n";
  std::cout << "Project id: " << this->project.id << "\n";
  std::cout << "Project budget: " << this->project.budget << "\n\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
  }

Tester::Tester(Project project, int salary, std::string fio, Position pos) {
  this->salary = salary;
  this->name = fio;
  this->position = pos;
  this->project = project;
  this->id = createId();
}

Tester::~Tester() {
}

int Tester::calcProAdditions() {
  return worktime * 1000;
}

void Tester::printInfo() {
  std::cout << "Tester "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Project: " << "\n\n";
  std::cout << "Project id: " << this->project.id << "\n";
  std::cout << "Project budget: " << this->project.budget << "\n\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
}

TeamLeader::TeamLeader(Project project, int salary, std::string fio,
  Position pos)
  : Programmer::Programmer(project, salary, fio, pos) {
}

TeamLeader::~TeamLeader() {
}

int TeamLeader::calcHeads() {
  return 3000 * this->subordinates_count;
}

void TeamLeader::calc() {
  this->payment = calcBase(this->salary, this->worktime);
  this->payment += calcBudgetPart(0.2f, this->project.budget);
  this->payment += calcHeads();
}

Project TeamLeader::getProject() {
  return this->project;
}

void TeamLeader::printInfo() {
  std::cout << "Team Leader "<< this->name << " :\n";
  std::cout << "Id: "<< this->id << "\n";
  std::cout << "Working hours: "<< this->worktime << "\n";
  std::cout << "Project: " << "\n\n";
  std::cout << "Project id: " << this->project.id << "\n";
  std::cout << "Project budget: " << this->project.budget << "\n\n";
  std::cout << "Count of his programmers: " << this->subordinates_count <<
    "\n";
  std::cout << "Payment: "<< this->payment << "\n\n\n";
  }
