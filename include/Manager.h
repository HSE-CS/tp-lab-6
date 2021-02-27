// Copyright 2021 GN
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include <vector>
#include "Engineer.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Heading, public ProjectBudget {
 private:
    Project* project;
    int subordinates = 0;

 public:
    explicit ProjectManager(int id_, std::string name_,
        Project* project_) : Employee(id_, name_) {
        project = project_;
        spec = PROJECTMANAGER;
    }
    virtual int calcHeads();
    virtual void calc();
    virtual int calcBudgetPart(float part_, int budget_);
    virtual int calcProAdditions() { return 0; }
    virtual void printInfo();
    int getSubordinates();
    void addSubordinates() {
        subordinates++;
    }
};

class SeniorManager : public ProjectManager {
 private:
    std::vector<Project*> projects;
    int subordinates = 0;

 public:
    explicit SeniorManager(int id_, std::string name_,
        Project* project_) : ProjectManager(id_, name_, project_) {
        spec = SENIORMANAGER;
    }
    void addSubordinates() {
        subordinates++;
    }
    int getSubordinates();
    virtual void calc();
    virtual int calcHeads();
    virtual int calcProAdditions();
};

#endif  // INCLUDE_MANAGER_H_
