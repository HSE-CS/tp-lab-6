// Copyright [2021] <Roman Balayan>

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Employee.h"

class Factory {
 public:
    explicit Factory(std::string filename);
    std::vector<std::unique_ptr<Employee> > getEmployees();
 private:
    std::string filename;
};
