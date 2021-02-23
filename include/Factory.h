//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "Employee.h"

class Project {
protected:
    int id;
    double budget;
public:
    Project(int id, double budget);
    ~Project();

    void setId(int id);
    void setBudget(double budget);

    int getId();
    double getBudget();
};

std::vector<Employee*> readData(std::string file_name);

#endif  // INCLUDE_FACTORY_H_
