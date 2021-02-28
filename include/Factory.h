// Copyright 2021 Artyom Lavrov


#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "Employee.h"


class Factory {
public:
	std::vector<Employee*> generateEmployees();
};


#endif  // INCLUDE_FACTORY_H_
