// Copyright 2021 alexgiving

#include "Driver.h"

Driver::Driver(size_t _id, std::string _name, size_t _position, size_t _worktime, size_t _salary) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setPosition(_position);
  this->setWorkTime(_worktime);
  this->setSalary(_salary);
  this->setPayment(this->calc());
}

size_t Driver::calc() const {
  return (this->calcBase() + this->calcBonus());
}

size_t Driver::calcBonus() const {
  return (this->calcBase() / 10); // Bonus is 10% from base payment
}
