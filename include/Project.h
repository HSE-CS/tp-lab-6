// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <iostream>

class Project {
 private:
	std::string id;
	int budget;
 public:
	Project(std::string id, int budget);
	std::string getId() {
		return this->id;
	}
	int getBudget() {
		return this->budget;
	}
};

#endif  INCLUDE_PROJECT_H_
