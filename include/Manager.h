// Copyright Baklanov 2021
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Interfaces.h"
#include "Employee.h"
#include "Factory.h"


class ProjectManager : public Heading, public Employee, public ProjectBudget {
 protected:
    std::vector<Project*> Projects;

 public:
    ProjectManager(std::vector<Project*> Projects,
        int id_,
        std::string position_,
        std::string name_,
        int worktime_,
        int payment_) :
        Employee(id_, position_,
            name_,
            worktime_,
            payment_),
        Projects(Projects) {}
    int calcHeads() override;
    void calc() override;
    void printinfo() override;
    int calcProAdditions() override;
    int calcBudjetPart(float part, int budget) override;
    void setProject(std::vector<Project*> Projects) {
        this->Projects = Projects;
    }
    std::vector<Project*> getProject() {
        return this->Projects;
    }
};

class SeniorManager : public ProjectManager {
 protected:
    Project* project;

 public:
    SeniorManager(Project* project,
        std::vector<Project*> Projects,
        int id_, std::string position_,
        std::string name_, int worktime_,
        int payment_) :
        ProjectManager(Projects, id_, position_,
            name_, worktime_,
            payment_),
        project(project) {}
    void calc() override;
    void printinfo() override;
    int calcProAdditions() override;
    int calcBudjetPart(float part, int budget) override;
    void setProject(Project* Project) {
        this->project = Project;
    }
    Project* getProject() {
        return this->project;
    }
};

#endif  // INCLUDE_MANAGER_H_
