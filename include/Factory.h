// Copyright 2021 asma
#pragma once
#ifndef FACTORY_H_
#define FACTORY_H_

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

#endif  // FACTORY_H_
