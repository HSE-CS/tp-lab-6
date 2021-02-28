// Copyright 2021 Kasyanov
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Engineer.h"
#include "Manager.h"
#include <string>
#include <vector>


class StaffFactory {
 private:
    std::string emp_filename;
    std::string proj_filename;
 public:
    StaffFactory(std::string, std::string);
    std::vector<Employee*> ReadEmployees();
};

#endif  // INCLUDE_FACTORY_H_
