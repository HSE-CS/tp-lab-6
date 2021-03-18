// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <iostream>
#include <vector>
#include "Project.h"
#include "Engineer.h"
#include "Manager.h"
#include "Personal.h"

class Factory {
 public:
	static std::vector<Employee*> makeStaff(std::string fileName);
};

#endif  INCLUDE_FACTORY_H_
