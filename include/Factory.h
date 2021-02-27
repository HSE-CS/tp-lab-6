// Copyright [2021] <Roman Balayan>

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>

#include "Employee.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"

class Factory {
 public:
    explicit Factory(std::string filename);
    std::vector<Employee* > getEmployees();
    std::vector<std::vector<std::string> > getNextLineAndSplitIntoTokens(std::istream& str);
 private:
    std::string filename;
};
