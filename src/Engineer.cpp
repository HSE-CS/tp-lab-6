#include "Engineer.h"

#include <iostream>

#define TESTER_PRO_ADDITIONS 15
#define PROGRAMMER_PRO_ADDITIONS 25
#define PER_HEAD 5

void Engineer::printInfo() {
  this->Employee::printInfo();
  std::cout << "PRO_ADDITIONS: " << calcProAdditions() << std::endl
            << "SALARY: " << calcBase(salary, worktime) << std::endl;
}
uint32_t Engineer::calcBudgetPart(float part, uint32_t budget) {
  return (uint32_t)(part * (float)budget);
}

uint32_t Engineer::calcProAdditions() { return 0; }

void Engineer::calc() {
  payment = calcBudgetPart(1.0 / (float)project->staff, project->budget) +
            calcProAdditions() + calcBase(salary, worktime);
}

uint32_t Tester::calcProAdditions() { return TESTER_PRO_ADDITIONS; }

uint32_t Programmer::calcProAdditions() { return PROGRAMMER_PRO_ADDITIONS; }

uint32_t TeamLeader::calcHeads() { return project->staff * PER_HEAD; }

void TeamLeader::calc() {
  payment = calcBudgetPart(1.0 / (float)project->staff, project->budget) +
            calcProAdditions() + calcBase(salary, worktime) + calcHeads();
}
