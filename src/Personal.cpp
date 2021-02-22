// Copyright 2021 alexgiving

#include "Personal.h"
#include <iostream>

void Personal::setSalary(size_t _salary) {
  this->salary = _salary;
}

size_t Personal::getSalary() const {
  return this->salary;
}

size_t Personal::calcBase() const {
  return (this->getWorktime() * this->getSalary());
}

void Personal::printInfo() {
  std::cout << std::endl
            << this->getName() << " (id: " << this-getId() << ") "
            << this->getPosition()
            << "\nSalary = " << this->getSalary() << "ph | WKHO = "
            << this->getWorktime() << " h"
            << "\nTotal = " << this->getPayment() << std::endl;
}

/*
 * Output:
 *
 * Alexey (id: 35) Cleaner
 * Salary = 500 ph | WKHO = 1 h
 * Total = 500
 */
