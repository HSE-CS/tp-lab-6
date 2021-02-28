// Copyright 2021 dmitrycvetkov2000
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Employee.h"
#include "Engineer.h"
#include "Project.h"

#include <string>
#include <unordered_map>
#include <vector>

class StaffFactory {
 public:
    std::vector<Employee*> makeStaff(const std::string& staffFile,
        const std::string& projFile);

 private:
    std::unordered_map<int, Project*> projects;
};


#endif  // INCLUDE_FACTORY_H_
