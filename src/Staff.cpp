// Copyright 2021 Rogov Andrey
#include "Staff.h"

#include <iostream>

#define BONUS 10

uint32_t Staff::calcBonus() { return 0; }

void Staff::printInfo() {
 this->Employee::printInfo();
 std::cout << "SALARY: " << calcBase(salary, worktime) << std::endl;
}
 uint32_t Staff::calcBase(uint32_t salary, uint32_t wtime) {
 	return salary * wtime;
}

uint32_t Driver::calcBonus() { return BONUS; }

void Driver::calc() { payment = calcBase(salary, worktime) + calcBonus(); }

void Janitor::calc() { payment = calcBase(salary, worktime) + calcBonus(); }
