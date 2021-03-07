// Copyright 2021 Dumarevskaya
#include "Engineer.h"
#include <iostream>

int Engineer::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void Engineer::calc() {
  payment = calcBase(salary, worktime) +
    calcBudgetPart(0.3, project->budget) + calcProAdditions()
    + calcBonus();
}

int Programmer::calcProAdditions() { return 1000; }


int TeamLeader::calcHeads() { return 100; }

int Tester::calcProAdditions() { return 500; }

void TeamLeader::calc() {
  payment = calcBase(salary, worktime) + calcProAdditions() + calcBonus();
}

int Engineer::calcBonus() {
  return 1000;
}

void Engineer::printInfo() {
  std::cout << "id: " << getId() << "\nname: "
    << getName() << "\nPosition: " << getPosition()
    << "\nWorktime: " << worktime << "\nPayment: " << payment
    << std::endl;
}
