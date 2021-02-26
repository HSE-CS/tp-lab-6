// Copyright Baklanov 2021
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <iostream>
#include <vector>
#include <string>
#include "Resource.h"
#include "Employee.h"

class Project {
 public:
    Project(int id, int budjet) :
        id(id), budjet(budjet), partForEngineers(0.1),
        partForManagers(0.25), partForSeniors(0.15) {}
    int id;
    int budjet;
    float partForEngineers;
    float partForManagers;
    float partForSeniors;
};

class FactorySalaries {
 public:
    int Engineer;
    int Programmer;
    int Tester;
    int TeamLeader;
    int Driver;
    int Cleaner;
};

std::vector<Employee*> makeStaff(Resource* a);

void makeStaffForProject(Resource* a,
    std::vector<Project*> Projects,
    std::vector<Employee*> Staff);

#endif  // INCLUDE_FACTORY_H_