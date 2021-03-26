// Copyright 2021 by mila
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "Employee.h"
#include "Interfaces.h"

class Project {
 private:
    int id = 0;
    std::vector<char> name;

 public:
    int budget;
    int team;
    Project(int id, std::string name, int budget)
         : id(id), name(name), budget(budget), team(0) {}
}

/*
- **ProjectManager** - проектный менеджер.
Получает зарплату из бюджета проекта
и за руководство участниками проекта.
*/

class ProjectManager : public Heading, public ProjectBudget {
 private:
    std::vector<Project *> projects;
    float part;
 public:
    ProjectManager(int id, std::string name, pos post,
                   std::vector<Project *> myProject, float part, int salary)
            : Employee(id, name, post, salary),
            projects(std::move(myProject)), part(part) {}

    int calcHeads() override;
    int calcBudgetPart(float part, int budget) override;
    int calcProAdditions() override;
    void calc() override;
    void printInfo() override;
}


/*
- **SeniorManager** - руководитель направления.
Получает из бюджетов всех проектов и за руководство всеми участниками.
*/

class SeniorManager : public ProjectManager {
 private:
    std::vector<Project *> projects;
    float part;
 public:
    SeniorManager(int id, std::string name, pos post,
                  std::vector<Project *> projects, float part, int salary)
               : ProjectManager(id, name, post,
                                std::move(projects), part, salary),
  void calc() override;
}


#endif  // INCLUDE_MANAGER_H_
