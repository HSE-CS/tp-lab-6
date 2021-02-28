// Copyright 2021 Artyom Lavrov


#include <Factory.h>
#include <fstream>
#include <Personal.h>
#include <iostream>
#include <Engineer.h>
#include <Manager.h>


std::vector<Employee*> Factory::generateEmployees() {
    std::vector<Employee*> employees;
    std::string line;
    std::ifstream in("EmployeesList.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            std::string id;
            std::string name;
            std::string position;
            std::string workTime;
            std::string salary;
            int i = 0;
            while (line[i] != ',') {
                id.push_back(line[i]);
                i++;
            }
            i++;
            i++;
            while (line[i] != ',') {
                name.push_back(line[i]);
                i++;
            }
            i++;
            i++;
            while (line[i] != ',') {
                position.push_back(line[i]);
                i++;
            }

            if (position == "Driver") {
                i++;
                i++;
                while (line[i] != ',') {
                    salary.push_back(line[i]);
                    i++;
                }
                employees.reserve(employees.size() + 1);
                employees.push_back(new Driver(id, name,
                    DRIVER,
                    std::stoi(salary)));
            } else if (position == "Cleaner") {
                i++;
                i++;
                while (line[i] != ',') {
                    salary.push_back(line[i]);
                    i++;
                }
                employees.reserve(employees.size() + 1);
                employees.push_back(new Cleaner(id, name,
                    CLEANER,
                    std::stoi(salary)));
            } else if (position == "Programmer") {
                i++;
                i++;
                while (line[i] != ',') {
                    salary.push_back(line[i]);
                    i++;
                }
                std::string projectId;
                i++;
                i++;
                while (line[i] != ',') {
                    projectId.push_back(line[i]);
                    i++;
                }

                employees.reserve(employees.size() + 1);
                employees.push_back(new Programmer(id,
                    name,
                    PROGRAMMER,
                    std::stoi(salary),
                    new Project(projectId, 100000)));
            } else if (position == "Tester") {
                i++;
                i++;
                while (line[i] != ',') {
                    salary.push_back(line[i]);
                    i++;
                }
                std::string projectId;
                i++;
                i++;
                while (line[i] != ',') {
                    projectId.push_back(line[i]);
                    i++;
                }

                employees.reserve(employees.size() + 1);
                employees.push_back(new Tester(id,
                    name,
                    TESTER,
                    std::stoi(salary),
                    new Project(projectId, 100000)));
            } else if (position == "TeamLeader") {
                i++;
                i++;
                while (line[i] != ',') {
                    salary.push_back(line[i]);
                    i++;
                }
                std::string projectId;
                i++;
                i++;
                while (line[i] != ',') {
                    projectId.push_back(line[i]);
                    i++;
                }

                employees.reserve(employees.size() + 1);
                employees.push_back(new TeamLeader(id,
                    name,
                    TEAMLEADER,
                    std::stoi(salary),
                    new Project(projectId, 100000)));
            } else if (position == "ProjectManager") {
                std::string projectId;
                i++;
                i++;
                while (line[i] != ',') {
                    projectId.push_back(line[i]);
                    i++;
                }
                std::vector<Project*> projects;
                projects.push_back(new Project(projectId, 100000));

                employees.reserve(employees.size() + 1);
                employees.push_back(new ProjectManager(id,
                    name,
                    TEAMLEADER,
                    projects));
            } else if (position == "SeniorManager") {
                std::vector<Project*> projects;

                while (line[i + 1] != '\n' && line[i + 1] != '\0') {
                    std::string projectId;
                    i++;
                    i++;
                    while (line[i] != ',') {
                        projectId.push_back(line[i]);
                        i++;
                    }
                    projects.push_back(new Project(projectId, 100000));
                }

                employees.reserve(employees.size() + 1);
                employees.push_back(new SeniorManager(id,
                    name,
                    SENIORMANAGER,
                    projects));
            }
        }
    } else {
        std::cout << "Open file error";
    }
    in.close();
    return employees;
}

