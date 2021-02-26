// Copyright 2021 JGMax

#include <fstream>
#include <iostream>
#include "Factory.h"
#include "Engineer.h"
#include "Manager.h"

std::vector<Employee*> StaffFactory::makeStuff(const std::string fileName) {
    std::ifstream file(fileName);
    std::vector<Project*> projects;
    std::vector<Employee*> employee;
    if (file.is_open()) {
        while(file.good()) {
            std::string type;
            std::string line;
            getline(file, type, ';');
            if (type == "project") {
                std::string id, title, budget;
                getline(file, id, ';');
                getline(file, title, ';');
                getline(file, budget, ';');
                auto* project = new Project(stoi(id), title, stod(budget));
                if (rand_r(12) % 2 == 0) {
                    project->closeProject();
                }
                projects.push_back(project);
            } else if (type == "employee") {
                std::string id, name, workTime, position, salary;
                getline(file, id, ';');
                getline(file, name, ';');
                getline(file, workTime, ';');
                getline(file, position, ';');
                if (position == "programmer") {
                    std::string projectId;
                    getline(file, salary, ';');
                    getline(file, projectId, ';');

                    employee.push_back(new
                    Programmer(stoi(id),
                               name,
                               stoi(workTime),
                               PROGRAMMER,
                               stoi(salary),
                               getProject(stoi(projectId), projects)
                               ));
                } else if (position == "team leader") {
                    std::string projectId;
                    getline(file, salary, ';');
                    getline(file, projectId, ';');

                    employee.push_back(new
                    TeamLeader(stoi(id),
                               name,
                               stoi(workTime),
                               TEAM_LEADER,
                               stoi(salary),
                               getProject(stoi(projectId), projects)
                               ));
                } else if (position == "engineer") {
                    std::string projectId;
                    getline(file, salary, ';');
                    getline(file, projectId, ';');

                    employee.push_back(new
                    Engineer(stoi(id),
                             name,
                             stoi(workTime),
                             ENGINEER,
                             stoi(salary),
                             getProject(stoi(projectId), projects)
                             ));
                } else if (position == "tester") {
                    std::string projectId;
                    getline(file, salary, ';');
                    getline(file, projectId, ';');

                    employee.push_back(new
                    Tester(stoi(id),
                           name,
                           stoi(workTime),
                           TESTER,
                           stoi(salary),
                           getProject(stoi(projectId), projects)
                           ));
                } else if (position == "personal") {
                    getline(file, salary, ';');
                    employee.push_back(new
                    Personal(stoi(id),
                             name,
                             stoi(workTime),
                             PERSONAL,
                             stoi(salary)
                             ));
                } else if (position == "cleaner") {
                    getline(file, salary, ';');
                    employee.push_back(new
                    Cleaner(stoi(id),
                            name,
                            stoi(workTime),
                            CLEANER,
                            stoi(salary)
                            ));
                } else if (position == "driver") {
                    std::string bonus;
                    getline(file, salary, ';');
                    getline(file, bonus, ';');
                    employee.push_back(new
                    Driver(stoi(id),
                           name,
                           stoi(workTime),
                           DRIVER,
                           stoi(salary),
                           stod(bonus)
                           ));
                } else if (position == "project manager") {
                    std::string projectId;
                    getline(file, projectId, ';');

                    employee.push_back(new
                    ProjectManager(stoi(id),
                                   name,
                                   stoi(workTime),
                                   PROJECT_MANAGER,
                                   getProject(stoi(projectId), projects)
                                   ));
                } else if (position == "senior manager") {
                    std::string projectId;
                    std::vector<Project*> vector;
                    while (projectId != ".") {
                        projectId.clear();
                        getline(file, projectId, ';');
                        if (projectId != ".") {
                            vector.push_back(getProject(stoi(projectId), projects));
                        }
                    }

                    employee.push_back(new
                    SeniorManager(stoi(id),
                                  name,
                                  stoi(workTime),
                                  SENIOR_MANAGER,
                                  vector));
                }
            }
            getline(file, type, '\n');
        }
    } else {
        std::cout << "Can not open file" << std::endl;
    }
    return employee;
}

Project *StaffFactory::getProject(int id, const std::vector<Project *> &projects) {
    for (auto& project : projects) {
        if (project && project->getId() == id) {
            return project;
        }
    }
    return nullptr;
}
