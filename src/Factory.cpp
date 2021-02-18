// Copyright 2021 soda
#include "Interfaces.h"

#include "Factory.h"
#include <iostream>

Project::Project(size_t id, size_t budget, std::string name) {
	this->id = id;
	this->budget = budget;
	this->name = name;
	this->employees = new std::vector<Employee*>;
	this->part = 0.0;
}

void hireWorker();
size_t getId();
size_t getBudget();
std::string getName();
size_t getNumWorker();
void setPart();
double getPart();