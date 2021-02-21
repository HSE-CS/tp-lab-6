//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_MANAGER_H
#define TP_LAB_6_MANAGER_H

#include <vector>
#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"


class ProjectManager : public Employee, public IProjectBudget, public IHeading {
protected:
    int num_of_projects = 1;
    std::vector<Project*> projects;
    float part;
public:
    ProjectManager(int id, const std::string &name, Position position,
                   const std::vector<Project *> &projects, float part);
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    int calcHeads() override;
    void calc() override;
};

class SeniorManager : public ProjectManager {
protected:
    int num_of_projects = 3;
public:
    SeniorManager(int id, const std::string &name, Position position,
                  const std::vector<Project *> &projects, float part);
    int calcProAdditions() override;
    void calc() override;
};


#endif //TP_LAB_6_MANAGER_H
