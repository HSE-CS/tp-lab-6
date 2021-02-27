// Copyright 2021 Andrey Bakurskii

#include "Engineer.h"

Project::Project(int id, int budget) {
  this->id = id;
  this->budget = budget;
}

int Engineer::calc() {
  return calcBase(getPayment(), getWorktime()) + calcBonus() +
         calcBudgetPart(0.02, project->budget) + calcProAdditions();
}

int Engineer::calcBase(int p,  int wt) {
  return p * wt;
}

int Engineer::calcBonus() { return Personal::calcBonus(); }

int Engineer::calcBudgetPart(float part, int budget) {
  int budgetpart = static_cast<int>(part * budget);
  return budgetpart;
}

int Engineer::calcProAdditions() { return calcBonus(); }

void Engineer::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  info += "Project: id - " + std::to_string(project->id) + " budget - " +
          std::to_string(project->budget) + "\n";

  std::cout << info;
}

Project* Engineer::getProject() { return this->project; }

int Tester::calc() {
  return calcBase(getPayment(), getWorktime()) + calcBonus() +
         calcBudgetPart(0.01, getProject()->budget) + calcProAdditions();
}

int Tester::calcBase(int p, int wt) { return Engineer::calcBase(p, wt); }

int Tester::calcBonus() { return Engineer::calcBonus(); }

int Tester::calcBudgetPart(float part, int budget) {
  return Engineer::calcBudgetPart(part, budget);
}

int Tester::calcProAdditions() { return calcBonus(); }

void Tester::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  info += "Project: id - " + std::to_string(getProject()->id) + " budget - " +
          std::to_string(getProject()->budget) + "\n";

  std::cout << info;
}

int Programmer::calc() {
  return calcBase(getPayment(), getWorktime()) + calcBonus() +
         calcBudgetPart(0.015, getProject()->budget) + calcProAdditions();
}

int Programmer::calcBase(int p, int wt) { return Engineer::calcBase(p, wt); }

int Programmer::calcBonus() { return Engineer::calcBonus(); }

int Programmer::calcBudgetPart(float part, int budget) {
  return Engineer::calcBudgetPart(part, budget);
}

int Programmer::calcProAdditions() { return calcBonus(); }

void Programmer::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  info += "Project: id - " + std::to_string(getProject()->id) + " budget - " +
          std::to_string(getProject()->budget) + "\n";

  std::cout << info;
}

int TeamLeader::calc() {
  return calcBase(getPayment(), getWorktime()) + calcBonus(),
         calcBudgetPart(0.015, getProject()->budget) + calcProAdditions() +
             calcHeads();
}

int TeamLeader::calcBase(int p, int wt) { return Programmer::calcBase(p, wt); }

int TeamLeader::calcBonus() { return Programmer::calcBonus(); }

int TeamLeader::calcBudgetPart(float part, int budget) {
  return Programmer::calcBudgetPart(part, budget);
}

int TeamLeader::calcProAdditions() { return calcBonus(); }

int TeamLeader::calcHeads() {
  int p = getPayment();
  int wt = getWorktime();
  int res = static_cast<int>(p * 0.1 * wt);
  return res;
}

void TeamLeader::printInfo() {
  std::string info = "";

  info += "ID: " + std::to_string(getId()) + "\n";
  info += "Name: " + getName() + "\n";
  info += "Position: " + getPosition() + "\n";
  info += "Payment (per 1 hours): " + std::to_string(getPayment()) + "\n";
  info += "Worktime: " + std::to_string(getWorktime()) + "\n";
  info += "Salary: " + std::to_string(calc()) + "\n";

  info += "Project: id - " + std::to_string(getProject()->id) + " budget - " +
          std::to_string(getProject()->budget) + "\n";

  std::cout << info;
}
