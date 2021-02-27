// Copyright [2021] <Roman Balayan>

#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <string>

#include "Interfaces.h"
#include "Employee.h"

class ProjectManager :  public Employee,
                        public IProjectBudget,
                        public IHeading {
 public:
    ProjectManager(unsigned int id,
        std::string name,
        Position position,
        unsigned int worktime,
        unsigned int payment,
        const std::vector<std::shared_ptr<Project> >& projects);
    int calcHeads() override;
    void calc() override;
    void printInfo() override;
 private:
    std::vector<std::shared_ptr<Project> > projects;
};

class SeniorManager :  public ProjectManager {
 public:
    SeniorManager(unsigned int id,
        std::string name,
        unsigned int worktime,
        unsigned int payment,
        const std::vector<std::shared_ptr<Project> >& projects);
    void calc() override;
    void printInfo() override;
 private:
    std::vector<std::shared_ptr<Project> > projects;
};
