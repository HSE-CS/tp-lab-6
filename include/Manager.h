//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_MANAGER_H
#define TP_LAB_6_MANAGER_H

#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public IProjectBudget, public IHeading {
public:
    int calcHeads() override;
    void calc() override;
};

class SeniorManager : public ProjectManager {
public:
    void calc() override;
};


#endif //TP_LAB_6_MANAGER_H
