// Copyright 2021 soda
#include "Interfaces.h"

#include "Employee.h"
#include "Personal.h"


size_t Personal::getSalary() {
	return salary;
}

size_t Personal::calcBase() {
	return (this->getWorktime() * this->getSalary());
}

Driver::Driver(size_t id, std::string name, size_t worktime,
	size_t position, size_t salary) {

	this->setId(id);
	this->setWorkTime(worktime);
	this->setPosition(position);
}

size_t Driver::calc() {
	return (this->calcBonus() + this->calcBase());
}

size_t Driver::calcBonus() {
	return rand() % 1000;
}

size_t Cleaner::calc() {
	return (this->calcBase());
}
