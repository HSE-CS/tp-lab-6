// Copyright 2021
#ifndef INCLUDE_SENIORMANAGER_H_
#define INCLUDE_SENIORMANAGER_H_
#include "ProjectManager.h"
#include "Project.h"
#include <vector>
#include <string>
class SeniorManager : public ProjectManager {
 private:
    std::vector<Project*> projects;
 public:
     SeniorManager(int id, std::string name,
         std::string position, std::vector<Project*> projects)
         : ProjectManager(id, name, position) {
         this->projects = projects;
     }
    void calc() override;
    void printInfo() override;
};
#endif  // INCLUDE_SENIORMANAGER_H_
