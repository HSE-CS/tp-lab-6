// Copyright 2021 mkhorosh

#include "Engineer.h"

int Engineer::calcBudgetPart(float current_part, int budget) {
  return (int) (current_project->budget / current_part);
}

void Engineer::calc() {
  payment = calcBase(salary, work_time) +
      calcBudgetPart(part, current_project->budget) + calcProAdditions() +
      calcBonus();
}

int Programmer::calcProAdditions() {
  return (int) (0.3 * salary);
}

int Programmer::calcBonus() {
  return (int) (0.1 * salary);
}

int Tester::calcProAdditions() {
  return (int) (0.25 * salary);
}

int Tester::calcBonus() {
  return (int) (0.15 * salary);
}

void Tester::calc() {
  payment = calcBase(salary, work_time) + calcProAdditions() + calcBonus();
}

int TeamLeader::calcHeads() {
  return (int) (0.25 * salary);
}

int TeamLeader::calcBonus() {
  return (int) (0.1 * salary);
}
