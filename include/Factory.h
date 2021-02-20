//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_FACTORY_H
#define TP_LAB_6_FACTORY_H

#include <vector>
#include "Employee.h"

class Project {
public:
    int is;
    std::string name;
    int budget;
};

class StaffFactory {
public:
    static std::vector<Project*> projects;
    static std::vector<Employee*> makeStaff();
};


#endif //TP_LAB_6_FACTORY_H
