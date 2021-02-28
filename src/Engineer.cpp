// Copyright 2021 Ksuvot
#include "Engineer.h"

Project* Engineer::getProject() {
  return project;
}

void Engineer::calc() {
  setPayment(calcBase(getSalary(), getWorktime())
    + calcBudgetPart(0.01, getProject()->budget)
    + calcProAdditions());
}

int Engineer::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * budget);
}

int Programmer::calcProAdditions() {
  return 500;
}

int Tester::calcProAdditions() {
  return 1000;
}

int TeamLeader::calcHeads() {
  return 1500;
}

void TeamLeader::calc() {
  setPayment(calcBase(getSalary(), getWorktime())
                 + calcProAdditions()
                 + calcHeads());
}
