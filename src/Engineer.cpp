// Copyright 2021 ArinaMonicheva

#include <stdlib.h>
#include "Engineer.h"


Engineer::Engineer(int id, std::string name, std::string position,
 double payment, Project* newProject) :
  Personal(id, name, position, payment) {
  project = newProject;
}

double Engineer::calcBudgetPart(double part) {
  return project->getBudget() * part;
}

Project* Engineer::getProject() {
  return project;
}

double Engineer::calcBonus() {
  return 0;
}

Programmer::Programmer(int id, std::string name, std::string position,
 double payment, Project* newProject) :
  Engineer(id, name, position, payment, newProject) {
}

double Programmer::calcProAdditions() {
  return (getProject()->getBudget() / getWorkTime()) * 10;
}

double Programmer::calc() {
  return calcBudgetPart(0.05) + calcBase() + calcProAdditions();
}

void Programmer::printInfo() {
  std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nNext salary: " + std::to_string(calc()) +
    "\nCurrent pro additions: " + std::to_string(calcProAdditions()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")" +
    "\nCurrent project: " + std::to_string(getProject()->getId());
  std::cout << info << std::endl;
}

TeamLeader::TeamLeader(int id, std::string name, std::string position,
 double payment, Project* newProject) :
  Programmer(id, name, position, payment, newProject) {
}

double TeamLeader::calcHeads() {  // excludes teamlead and manager
  return (getProject()->getStaffNum() - 2) * 1000.0;
}

double TeamLeader::calc() {
  return calcBudgetPart(0.1) + calcBase() + calcHeads();
}

void TeamLeader::printInfo() {
  std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nNext salary: " + std::to_string(calc()) +
    "\nCurrent pro additions: " + std::to_string(calcProAdditions()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")" +
    "\nCurrent project: " + std::to_string(getProject()->getId()) +
    "\nNumber of subordinates: " +
    std::to_string(getProject()->getStaffNum() - 2);
  std::cout << info << std::endl;
}

Tester::Tester(int id, std::string name, std::string position,
 double payment, Project* newProject) :
  Engineer(id, name, position, payment, newProject) {
}

double Tester::calcProAdditions() {
  time_t* n = NULL;
  unsigned int* seed = 0;
  srand(time(n));

  return rand_r(seed) % 300 * 100.0 + 10000.0;
}

void Tester::printInfo() {
    std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nNext salary: " + std::to_string(calc()) +
    "\nCurrent pro additions: " + std::to_string(calcProAdditions()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")" +
    "\nCurrent project: " + std::to_string(getProject()->getId()) +
    "\nMistakes fixed: " +
    std::to_string(static_cast<int>((calcProAdditions() - 10000.0) / 100.0));
  std::cout << info << std::endl;
}

double Tester::calc() {
  return calcBase() + calcProAdditions();
}
