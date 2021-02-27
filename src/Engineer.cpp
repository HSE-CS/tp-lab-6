// Copyright 2021 Pavlova D.

#include "Engineer.h"

int Engineer::calcBudgetPart(float _part, int budget) {
  return myProject->Budget / static_cast<int>(_part);
}

void Engineer::calc() {
  payment = calcBase(salary, worktime) +
            calcBudgetPart(part, myProject->Budget) + calcProAdditions() +
            calcBonus();
}

int Programmer::calcProAdditions() { return static_cast<int>(salary * 0.15); }

int Programmer::calcBonus() { return 10; }

int TeamLeader::calcHeads() { return 4; }

int TeamLeader::calcBonus() { return calcHeads() * 10; }

int Tester::calcProAdditions() { return static_cast<int>(salary * 0.5); };

int Tester::calcBonus() { return 30; }

void Tester::calc() {
  payment = calcBase(salary, worktime) + calcProAdditions() + calcBonus();
}
