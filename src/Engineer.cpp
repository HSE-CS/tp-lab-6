#include "Engineer.h"

#include <iostream>

void Engineer::printInfo() {
  Staff::printInfo();
  std::cout << "PRO_ADDITIONS: " << calcProAdditions() << std::endl
            << "PROJECT_BUDGET: " << project.budget << std::endl
            << "PROJECT_STAFF: " << project.staff_num << std::endl;
}
uint32_t Engineer::calcBudgetPart(float part, uint32_t budget) {
  return (uint32_t)(part * static_cast<float>(budget));
}

uint32_t Engineer::calcProAdditions() { return 0; }

void Engineer::calc() {
  payment = calcBudgetPart(1.0 / static_cast<float>(project.staff_num),
                           project.budget) +
            calcProAdditions() + calcBase(salary, worktime);
}

uint32_t Tester::calcProAdditions() { return TESTER_PRO_ADDITIONS; }

uint32_t Programmer::calcProAdditions() { return PROGRAMMER_PRO_ADDITIONS; }

uint32_t TeamLeader::calcHeads() {
  return project.staff_num * TEAMLEADER_PER_HEAD;
}

void TeamLeader::calc() {
  payment = calcBudgetPart(1.0 / static_cast<float>(project.staff_num),
                           project.budget) +
            calcProAdditions() + calcBase(salary, worktime) + calcHeads();
}
