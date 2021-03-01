// Copyright 2020 Polina Lukicheva
#include "Engineer.h"
#include "iostream"

int Engineer::calcBudgetPart(float part, int budget) {
  return part * budget;
}

int Engineer::calcProAdditions() {
  return Personal::calcBonus();
}

Project* Engineer::getProject() {
  return project;
}


int Engineer::calc() {
  return Personal::calc();
}

void Engineer::printInfo() {
  {
    std::cout << "{id=" + std::to_string(getId()) +
      ", name=" + getName() +
      ", position=" + getPosition() +
      ", payment=" + std::to_string(getPayment()) +
      ", salary" + std::to_string(getSalary()) + "}";
    if (getProject() != nullptr) {
      std::cout <<
        ", project id " + std::to_string(getProject()->id) +
        ", project budget " + std::to_string(getProject()->budget) << std::endl;
    } else {
      std::cout << std::endl;
    }
  }
}

int Tester::calcAdditions() {
  return Personal::calcBonus();
}

int Tester::calcBonus() {
  return Personal::calcBonus();
}

int Tester::calc() {
  return Engineer::calc() + calcBonus() + calcProAdditions();
}

int Tester::calcProAdditions() {
  return Personal::calcBonus();
}

void Tester::printInfo() {
  std::cout << "{id=" + std::to_string(getId()) +
    ", name=" + getName() +
    ", position=" + getPosition() +
    ", payment=" + std::to_string(getPayment()) +
    ", salary" + std::to_string(getSalary()) + "}";
  if (getProject() != nullptr) {
    std::cout << ", project id " + std::to_string(getProject()->id) +
      ", project budget " + std::to_string(getProject()->budget) << std::endl;
  } else {
    std::cout << std::endl;
  }
}

int Programmer::calcBonus() {
  return Engineer::calcBonus();
}

int Programmer::calc() {
  return Engineer::calc() + calcBonus() + calcProAdditions();
}

int Programmer::calcProAdditions() {
  return Personal::calcBonus();
}

void Programmer::printInfo() {
  std::cout << "{id=" + std::to_string(getId()) +
    ", name=" + getName() +
    ", position=" + getPosition() +
    ", payment=" + std::to_string(getPayment()) +
    ", salary" + std::to_string(getSalary()) + "}";
  if (getProject() != nullptr) {
    std::cout << ", project id " + std::to_string(getProject()->id) +
      ", project budget " + std::to_string(getProject()->budget) << std::endl;
  } else {
    std::cout << std::endl;
  }
}

int TeamLeader::calcHeads() {
  return static_cast<int>(getProject()->budget * 0.1);
}

int TeamLeader::calc() {
  return Engineer::calc() + calcBonus() + calcProAdditions();
}

int TeamLeader::calcBonus() {
  return Engineer::calcBonus();
}

void TeamLeader::printInfo() {
  std::cout << "{id=" + std::to_string(getId()) +
    ", name=" + getName() +
    ", position=" + getPosition() +
    ", payment=" + std::to_string(getPayment()) +
    ", salary" + std::to_string(getSalary()) + "}";
  if (getProject() != nullptr) {
    std::cout << ", project id " + std::to_string(getProject()->id) +
      ", project budget " + std::to_string(getProject()->budget) << std::endl;
  } else {
    std::cout << std::endl;
  }
}
