// Copyright 2021 mkhorosh

#include "Engineer.h"

int Engineer::calcBudgetPart(float current_part, int budget) {
  return static_cast<int> (current_project->budget / current_part);
}

void Engineer::calc() {
  payment = calcBase(salary, work_time) +
      calcBudgetPart(part, current_project->budget) + calcProAdditions() +
      calcBonus();
}

int Programmer::calcProAdditions() {
  return static_cast<int> (0.3 * salary);
}

int Programmer::calcBonus() {
  return static_cast<int> (0.1 * salary);
}

int Tester::calcProAdditions() {
  return static_cast<int> (0.25 * salary);
}

int Tester::calcBonus() {
  return static_cast<int> (0.15 * salary);
}

void Tester::calc() {
  payment = calcBase(salary, work_time) + calcProAdditions() + calcBonus();
}

int TeamLeader::calcHeads() {
  return static_cast<int> (0.25 * salary);
}

int TeamLeader::calcBonus() {
  return static_cast<int> (0.1 * salary);
}
