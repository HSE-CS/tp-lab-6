// Copyright 2021 Elise
#include "Engineer.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

size_t Engineer::calcBudgetPart(float part, int budget) {
  return project->budget / static_cast<int>(part);
}

float Engineer::getPart() { return part; }

void Engineer::printInfo() {
  std::cout << std::endl
            << this->get_id() << " - " << this->get_name() << " - "
            << this->get_position() << "\nSalary = " << this->get_salary()
            << "\nWorktime = " << this->get_worktime()
            << "\nFinal payment = " << this->calc() << std::endl;
}

size_t Tester::calcProAdditions() {
  return calcBase(get_salary(), get_worktime()) / 15;
}

int Tester::calc() {
  payment = calcBase(get_salary(), get_worktime()) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}

size_t Programmer::calcProAdditions() {
  return calcBase(get_salary(), get_worktime()) / 10;
}

int Programmer::calc() {
  payment = calcBase(get_salary(), get_worktime()) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}

size_t TeamLeader::calcHeads() { return 15000; }

int TeamLeader::calc() {
  payment = calcBase(get_salary(), get_worktime()) + calcHeads() +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}