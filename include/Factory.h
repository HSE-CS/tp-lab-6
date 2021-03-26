// Copyright 2021 Krayushkina

#pragma once
#define FACTORY_H
#ifdef FACTORY_H
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"

std::vector<std::string> split(const std::string& s, char delimiter);
class Factory {
 public:
	static Employee* createEmployee(std::vector<std::string> data);
};

#endif // FACTORY_H