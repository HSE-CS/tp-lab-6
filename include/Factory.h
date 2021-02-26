// Copyright 2021 JGMax

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "Employee.h"

class StaffFactory {
 private:
    static Project* getProject(int id, std::vector<Project*> &projects);
 public:
    static std:: vector <Employee*> makeStuff(std::string fileName);
};

#endif  // INCLUDE_FACTORY_H_
