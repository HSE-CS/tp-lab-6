// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager: public Employee, public ProjectBudget {
 public:
    ProjectManager();
    explicit ProjectManager(std::string id, std::string name,
        std::string position, std::vector<Project> new_projects)
        :Employee(id, name, position) {
        projects = new_projects;
    }
    int calcHeads();
    void calc() override;
    void printInfo() override;
    int calcBugetPart(float, int) override;
    int calcProAdditins() override;
    std::vector<Project> getProjects();

 private:
    std::vector<Project> projects;
};

class SeniorManager: public ProjectManager {
 public:
    SeniorManager();
    explicit SeniorManager(std::string id, std::string name,
        std::string position, std::vector<Project> new_projects)
        :ProjectManager(id, name, position, new_projects) {
    }
    void calc() override;
};
#endif  // INCLUDE_MANAGER_H_
