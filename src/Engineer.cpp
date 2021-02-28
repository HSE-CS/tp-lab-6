// Copyright 2021 Schenikova

#include "Engineer.h"

float Engineer::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void Engineer::calc() {
  payment = calcBase() + calcBudgetPart(part, project.budget);
}

void Engineer::setPro(int pro) {
  this->pro = pro;
}

void Engineer::printInfo() {
  std::cout << name << " " << id << " " << position;
}

unsigned int Tester::calcProAdditions() {
  return pro;
}

void Tester::calc() {
  payment = calcBase() + calcBudgetPart(part, project.budget) + calcProAdditions();
}

unsigned int Programmer::calcProAdditions() {
  return pro;
}

void Programmer::calc() {
  payment = calcBase() + calcBudgetPart(part, project.budget) + calcProAdditions();
}

// int Programmer::getPayment() {
//   return this->payment;
// }

unsigned int TeamLeader::calcHeads() {
  return programmers.size() * percent;
}

void TeamLeader::calc() {
  payment = calcBase() + calcBudgetPart(part, project.budget) + calcHeads();
}
