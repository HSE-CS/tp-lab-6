// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <include/interfaces.h>
#include "Employee.h"
#include <iostream>
#include <vector>
#include <string>

class Project {
 private:
    unsigned int id;
    std::string name;
    int budget = 0;
    unsigned int numberOfArticipants = 0;

 public:
    Project(int, std::string);

    unsigned int getId() const;

    int getBudget() const;

    void setBudget(int budget);

    unsigned int getNumberOfArticipants() const;

    const std::string &getName() const;

    void setName(const std::string &name);

    void addArticipants();
};

class ProjectManager : public Employee, public IProjectBudget, public IHeading {
 private:
    Project project = Project(-1, "None");
    float partOfTheProject = 0;

 public:
    ProjectManager(unsigned int id, std::string name, Position position);

    const Project &getProject() const;

    void setProject(const Project &project);

    float getPartOfTheProject() const;

    void setPartOfTheProject(float partOfTheProject);

    int calcBudgetPart(float part, int budget) override;

    int calcProAdditions() override;

    int calcHeads() override;

    void calc() override;

    void printInfo() override;
};

class SeniorManager : public ProjectManager {
 private:
    std::vector<Project> projects;

 public:
    SeniorManager(unsigned int id, std::string name, Position position);

    void addProject(const Project &project);

    void calc() override;

    void printInfo() override;
};

#endif  // INCLUDE_MANAGER_H_
