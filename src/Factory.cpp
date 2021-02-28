// Copyright 2021 Nikolaev Ivan

#include "Factory.h"
#include "Employee.h"
#include <iostream>
#include <fstream>

std::vector<Project*> Factory::getProjects() {
    return projects;
}
void Factory::addProject(Project* project) {
    this->projects.push_back(project);
}

std::vector<Employee*> Factory::makeStaff() {
    std::vector<Employee*> employees;

    std::string line;
    std::string path("workers.txt");

    int employeeId;
    std::string employeeName = "NoName";
    Position employeePosition;
    std::string employeePositionStr = "";
    int employeeSalary = 0;
    Project* employeeProject = NULL;

    std::ifstream in(path);
    if (in.is_open()) {
        bool fillProjects = true;
        int projectId = 0;
        int projectBudget = 0;
        while (getline(in, line)) {
            if (line.find("WORKERS:") != -1) {
                fillProjects = false;
                continue;
            }
            if (fillProjects) {
                if (line.find("id:") != -1) {
                    int end = line.find('\0');
                    projectId = std::stoi(line.substr(3, end - 4));
                }
                if (line.find("budget:") != -1) {
                    int end = line.find('\0');
                    projectBudget = std::stoi(line.substr(7, end - 8));
                    addProject(new Project(projectId, projectBudget));
                }
            } else {
                if (line.find("id:") != -1) {
                    int end = line.find('\0');
                    employeeId = std::stoi(line.substr(3, end - 4));
                }
                if (line.find("name:") != -1) {
                    int end = line.find('\0');
                    employeeName = line.substr(5, end - 6);
                }
                if (line.find("position:") != -1) {
                    int end = line.find('\0');
                    employeePositionStr = line.substr(9, end - 10);
                }
                if (line.find("salary:") != -1) {
                    int end = line.find('\0');
                    employeeSalary = std::stoi(line.substr(7, end - 8));
                    if (employeePositionStr == "cleaner" ||
                        employeePositionStr == "driver") {
                        if (employeePositionStr == "cleaner") {
                            employees.push_back(new Cleaner(employeeId,
                                employeeName, CLEANER, 0, employeeSalary));
                        }
                        if (employeePositionStr == "driver") {
                            employees.push_back(new Driver(employeeId,
                                employeeName, DRIVER, 0, employeeSalary));
                        }
                    }
                }
                if (line.find("project:") != -1) {
                    int end = line.find('\0');
                    int projectId = std::stoi(line.substr(8, end - 9));
                    for (auto p : getProjects()) {
                        if (p->id == projectId) {
                            employeeProject = p;
                        }
                    }
                    if (employeePositionStr == "engineer") {
                        employees.push_back(new Engineer(employeeId,
                            employeeName, ENGINEER, 0, employeeSalary,
                            employeeProject));
                    }
                    if (employeePositionStr == "programmer") {
                        employees.push_back(new Programmer(employeeId,
                            employeeName, PROGRAMMER, 0, employeeSalary,
                            employeeProject));
                    }
                    if (employeePositionStr == "tester") {
                        employees.push_back(new Programmer(employeeId,
                            employeeName, TESTER, 0, employeeSalary,
                            employeeProject));
                    }
                    if (employeePositionStr == "team leader") {
                        employees.push_back(new Programmer(employeeId,
                            employeeName, TEAMLEADER, 0, employeeSalary,
                            employeeProject));
                    }
                    if (employeePositionStr == "project manager") {
                        employees.push_back(new Programmer(employeeId,
                            employeeName, PROJECTMANAGER, 0, employeeSalary,
                            employeeProject));
                    }
                }
                if (line.find("projects:") != -1) {
                    int end = line.find('\0');
                    std::string projectsStr = line.substr(9, end - 10);
                    std::vector<Project*> seniorProjects;
                    std::string currentId = "";
                    for (int i = 0; i < projectsStr.length(); i++) {
                        if (projectsStr[i] != ',') {
                            currentId += projectsStr[i];
                        } else {
                            for (auto p : getProjects()) {
                                if (p->id == std::stoi(currentId)) {
                                    seniorProjects.push_back(p);
                                }
                            }
                            currentId = "";
                        }
                    }
                    employees.push_back(new SeniorManager(employeeId,
                        employeeName, SENIORMANAGER, 0, seniorProjects));
                }
            }
        }
    }
    return employees;
    in.close();
}
