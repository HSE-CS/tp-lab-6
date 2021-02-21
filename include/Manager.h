// Copyright 2021 soda
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "Interfaces.h"

class ProjectManager : public Employee {
 private:
    std::vector<Project*>* projects;

 public:
    ProjectManager();
    ProjectManager(size_t id, std::string name, size_t worktime,
        size_t position, Project* proj);
    void setProject(Project*);
    size_t calc();
    size_t calcBugetParts();
    size_t NumOfProjects();
    std::stringbuf getProjectNames();
    std::string getProjectName();
    Project* getProject(size_t);
    std::vector<Project*>* getProjects();
    size_t calcHeads();
    void printInfo();
};

class SeniorManager : public ProjectManager {
 public:
    SeniorManager(size_t id, std::string name, size_t worktime,
        size_t position, std::vector<Project*>* proje);
    size_t calc();
    void printInfo();
};

#endif  // INCLUDE_MANAGER_H_
