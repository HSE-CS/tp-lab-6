// Copyright 2021 soda
#include "Interfaces.h"

#include "Factory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "json.hpp"



Project::Project(size_t id, size_t budget, std::string name) {
	this->id = id;
	this->budget = budget;
	this->name = name;
	this->employees = new std::vector<Employee*>;
	this->part = 0;
}

void Project::hireWorker(Employee* emp) {
	employees->push_back(emp);
	this->setPart();
}

size_t Project::getId() {
	return this->id;
}

size_t Project::getBudget() {
	return this->budget;
}

std::string Project::getName() {
	return this->name;
}

size_t Project::getNumWorker() {
	return employees->size();
}

void Project::setPart() {
	this->part = this->getBudget() / this->getNumWorker();
}

size_t Project::getPart() {
	this->setPart();
	return part;
}