#include "Staff.h"

#include <iostream>

uint32_t Staff::calcBonus() { return 0; }

void Staff::printInfo() {
  Employee::printInfo();
  std::cout << "SALARY: " << salary << std::endl;
}
uint32_t Staff::calcBase(uint32_t salary, uint32_t wtime) {
  return salary * wtime;
}

uint32_t Driver::calcBonus() { return BONUS; }

void Driver::calc() { payment = calcBase(salary, worktime) + calcBonus(); }

void Janitor::calc() { payment = calcBase(salary, worktime) + calcBonus(); }
