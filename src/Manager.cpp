// Copyright 2021 Lab_6 TiNa
#include "Manager.h"
#include <math.h>
#include <iostream>
#include <string>

float ProjectManager::calcBudgetPart(float contrib, int budget) {
  return floor(contrib * budget);
}

int ProjectManager::calcProAdditions() {
  int sum = 0;
  for (int i = 0; i < size(projects); i++) {
    sum += projects[i]->budget;
  }
  return calcBudgetPart(contrib, sum) / 33;
}

int ProjectManager::calcHeads() {
  int sum = 0;
  for (int i = 0; i < size(projects); i++) {
    sum += projects[i]->budget * 0.3;
  }
  return sum;
}

int ProjectManager::calc() {
  int sum = 0;
  for (int i = 0; i < size(projects); i++) {
    sum += projects[i]->budget;
  }
  payment = calcBudgetPart(contrib, sum) + calcProAdditions() + calcHeads();
  return payment;
}

void ProjectManager::printInfo() {
  std::cout << "Info:" << std::endl;
  std::cout << "Id:\t" << getId() << std::endl;
  std::cout << "Name:\t" << getName() << std::endl;
  std::cout << "Position:\t" << getPosition() << std::endl;
  std::cout << "Work time:\t" << getWorktime() << std::endl;
  // std::cout << "Payment:\t" << getPayment() << std::endl;
}
