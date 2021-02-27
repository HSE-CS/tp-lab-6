#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Interfaces.h"
#include "Employee.h"

class ProjectManager : public Employee,
                       public IProjectBudget,
                       public IHeading {
public:
    ProjectManager(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        std::vector<std::shared_ptr<Project> >& projects);
    virtual int calcHeads() override;
    virtual void calc() override;
    virtual void printInfo() override;
private:
    std::vector<std::shared_ptr<Project> > projects;
};

class SeniorManager : public ProjectManager {
public:
    SeniorManager(unsigned int id,
        std::string name,
        unsigned int worktime,
        unsigned int payment,
        std::vector<std::shared_ptr<Project> >& projects);
    virtual void calc() override;
    virtual void printInfo() override;
private:
    std::vector<std::shared_ptr<Project> > projects;
};