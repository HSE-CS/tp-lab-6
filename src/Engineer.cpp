// Copyright 2020 S. BOR

#include "Engineer.h"

unsigned Engineer::calcBudgetPart(float part, int budget) {
  return static_cast<unsigned>(part * budget);
}

unsigned Engineer::calcBonus(unsigned overtimeJob, unsigned cost) {
  return 0;
}

void Engineer::printInfo() {
  this->calc();
  std::cout << this->name << " " << this->position << " " << this->payment
  << std::endl;
}

void Engineer::calc() {
  payment = calcBase() + calcBudgetPart(0.1f, project.budget);
}

unsigned Programmer::calcProAdditions() {
  return 500;
}

void Programmer::calc() {
  payment = calcBase() + calcBudgetPart(0.1f, project.budget) +
  calcProAdditions();
}

unsigned Tester::calcProAdditions() {
  return 300;
}

void Tester::calc() {
  payment = calcBase() + calcBudgetPart(0.1f, project.budget) +
  calcProAdditions();
}

unsigned TeamLeader::calcHeads(int numberOfWorkers) {
  return numberOfWorkers * 100;
}

void TeamLeader::calc() {
  payment = calcBase() + calcBudgetPart(0.1f, project.budget) +
  calcProAdditions() + calcHeads(5);
}
