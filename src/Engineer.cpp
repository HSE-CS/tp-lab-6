// Copyright 2021 me

#include "..\include\Engineer.h"

int Engineer::calcBudgetPart(float part, int budget) { return part * budget; }

int Engineer::getProgectBudget() { return project->getBudget(); }

int Engineer::getProjectState() { return project->getWorkers(); }

int Engineer::getProjectTesters() { return project->getTesters(); }

void Engineer::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) +
             calcBudgetPart(0.3 / getProjectState(), project->getBudget()));
}

void Engineer::printInfo() {
  std::cout << "Employee:\n";
  std::cout << "\tName: " << getName() << "\n";
  std::cout << "\tId: " << getId() << "\n";
  std::cout << "\tPosition: " << getPosition() << "\n";
  std::cout << "\tWork time: " << getWorkTime() << "\n";
  std::cout << "\tSalary: " << getSalary() << "\n";
  std::cout << "\tProject ID: " << project->getProjectID() << "\n";
  std::cout << "\tProject budget: " << project->getBudget() << "\n";
}

int Engineer::calcProAdditions() {
  return calcBase(getSalary(), getWorkTime()) / 2;
}

void Tester::calc() {
  setPayment(calcProAdditions() + calcBase(getSalary(), getWorkTime()) +
             calcBudgetPart(0.2 / getProjectTesters(), getProgectBudget()));
}

void Tester::printInfo() {
    Engineer::printInfo();
    std::cout << "\tBudget part: " << 0.2 / getProjectTesters() << "\n";
    std::cout << "\tPayment: " << getPayment() << "\n";
}

void Programmer::calc() {
  setPayment(calcBudgetPart(0.3 / getProjectState(), getProgectBudget()) +
             calcProAdditions() + calcBase(getSalary(), getWorkTime()));
}

void Programmer::printInfo() {
  Engineer::printInfo();
  std::cout << "\tBudget part: " << 0.3 / getProjectState() << "\n";
  std::cout << "\tPayment: " << getPayment() << "\n";
}

int TeamLeader::calcHeads() {
  return calcBase(getSalary(), getWorkTime()) * 0.5;
}

void TeamLeader::calc() {
  setPayment(calcHeads() + calcBudgetPart(0.2, getProgectBudget()) +
             calcProAdditions() + calcBase(getSalary(), getWorkTime()));
}

void TeamLeader::printInfo() {
  Engineer::printInfo();
  std::cout << "\tBudget part: " << 0.2 << "\n";
  std::cout << "\tPayment: " << getPayment() << "\n";
}
