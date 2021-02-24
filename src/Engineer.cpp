// Copyright 2021 Smirnov Grigory
#include "Engineer.h"

Project* Engineer::getProject() {
  return project;
}

int Engineer::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * budget);
}

void Engineer::calc() {
  setPayment(calcBase(getSalary(), getWorkTime())
    + calcBudgetPart(0.01, getProject()->budget)
    + calcProAdditions());
}

int Programmer::calcProAdditions() {
  int result = 0;
  if (getWorkTime() > 100)
    result += 15000;
  if (getProject()->budget > 200000)
    result += 3000;
  return result;
}

void Tester::incErrorsFound() {
  errorsFound++;
}

int Tester::getErrorsFound() {
  return errorsFound;
}

int Tester::calcProAdditions() {
  return getErrorsFound() * 300;
}

int TeamLeader::getSubbordinates() {
  return subordinates;
}

int TeamLeader::calcHeads() {
  return getSubbordinates() * 1000;
}

void TeamLeader::calc() {
  setPayment(calcBase(getSalary(), getWorkTime())
    + calcProAdditions()
    + calcHeads());
}

void Engineer::printInfo() {
  std::cout << getName() + " " + std::to_string(getId())
    +std::to_string(getProject()->id) + " " + std::to_string(getPayment());
}
