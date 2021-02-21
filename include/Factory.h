//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_FACTORY_H
#define TP_LAB_6_FACTORY_H

#include <utility>
#include <vector>
#include "Employee.h"

class Project {
public:
    int is;
    std::string name;
    int budget;
    Project(int is, std::string name, int budget) :
    is(is), name(std::move(name)), budget(budget) {}
};

class StaffFactory {
public:
    static std::vector<Employee*> makeStaff();
};


#endif //TP_LAB_6_FACTORY_H
