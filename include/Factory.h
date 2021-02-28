// Copyright 2021
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include "Employee.h"
#include <vector>
#include "Project.h"

class Factory {

private:
    std::vector<Employee*> staff;
    std::vector<Project*> projects;
public:
    Factory() {
        projects.push_back(new Project(1, 1000000, "VTB"));
        projects.push_back(new Project(2, 2000000, "Yandex"));
        projects.push_back(new Project(3, 3000000, "SberBank"));
    }
    void makeStaff(std::string filename);
    void setAllWorkTime();
    void calcPayment();
    void printAllInfo();
    Project* getProject(std::string name);
};
#endif  // INCLUDE_FACTORY_H_
