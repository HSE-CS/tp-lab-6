// Copyright 2021 alexgiving

#include "Personal.h"

#include <iostream>

// Personal class

void Personal::setSalary(size_t _salary) {
  this->salary = _salary;
}

size_t Personal::getSalary() const {
  return this->salary;
}

size_t Personal::calcBase() const {
  return (this->getWorktime() * this->getSalary());
}

/*
 * Output:
 *
 * Alexey (id: 35) Cleaner
 * Salary = 500 ph | WKHO = 1 h
 * Total = 500
 */

void Personal::printInfo() {
  std::cout << std::endl
            << this->getName() << " (id: " << this-getId() << ") "
            << this->getPosition()
            << "\nSalary = " << this->getSalary() << "ph | WKHO = "
            << this->getWorktime() << " h"
            << "\nTotal = " << this->getPayment() << std::endl;
}

// Cleaner class

Cleaner::Cleaner(size_t _id, std::string _name, std::string _position, size_t _worktime, size_t _salary) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setPosition(std::move(_position));
  this->setWorkTime(_worktime);
  this->setSalary(_salary);
  this->setPayment(this->calc());
}

  size_t Cleaner::calc() const {
  return this->calcBase();
}

// Driver class

Driver::Driver(size_t _id, std::string _name, std::string _position, size_t _worktime, size_t _salary) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setPosition(std::move(_position));
  this->setWorkTime(_worktime);
  this->setSalary(_salary);
  this->setPayment(this->calc());
}

size_t Driver::calc() const {
  return (this->calcBase() + this->calcBonus());
}

size_t Driver::calcBonus() const {
  return (this->calcBase() / 10); // Bonus is 10% from salary
}


