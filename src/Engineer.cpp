// Copyright 2021 Lab_6 TiNa
#include "Engineer.h"
#include <iostream>
#include <string>
#include <math.h>

float Engineer::calcBudgetPart(float contrib, int budget) {
  return floor(contrib * budget);
}

void Engineer::printInfo() {
  std::cout << "Info:" << std::endl;
  std::cout << "Id:\t" << getId() << std::endl;
  std::cout << "Name:\t" << getName() << std::endl;
  std::cout << "Position:\t" << getPosition() << std::endl;
  std::cout << "Work time:\t" << getWorktime() << std::endl;
  std::cout << "Payment:\t" << getPayment() << std::endl;
}

int Programmer::calcProAdditions() { return calcBonus(); }

int Programmer::calc() {
  payment = calcBase(getPayment(), getWorktime()) +
            calcBudgetPart(contrib, project->budget) + calcProAdditions();
  return payment;
}

void Programmer::printInfo() {
  std::cout << "Info:" << std::endl;
  std::cout << "Id:\t" << getId() << std::endl;
  std::cout << "Name:\t" << getName() << std::endl;
  std::cout << "Position:\t" << getPosition() << std::endl;
  std::cout << "Work time:\t" << getWorktime() << std::endl;
  std::cout << "Payment:\t" << getPayment() << std::endl;
}

int Tester::calcProAdditions() { return calcBonus(); }

int Tester::calc() {
  payment = calcBase(getPayment(), getWorktime()) +
            calcBudgetPart(contrib, project->budget) + calcProAdditions();
  return payment;
}

int TeamLeader::calcHeads() { return 100; }

int TeamLeader::calc() {
  payment = calcBase(getPayment(), getWorktime()) +
            calcBudgetPart(contrib, project->budget) + calcProAdditions() + calcHeads();
  return payment;
}
