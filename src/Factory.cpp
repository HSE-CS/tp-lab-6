// Copyright 2021 dash
#include "Factory.h"

std::vector<Employee*> Factory::createemployees
(std::string prfile, std::string employeesfile) {
    std::ifstream project_file(prfile);
    std::vector<Project*> projects;
    int p_id, p_budget;
    std::vector<Employee*> employees;
    int id, worktime, payment, salary;
    std::string name, pos;
    Project* project;

    while (project_file >> p_id) {
        projects.push_back(new Project(p_id, p_budget));
    }
    project_file.close();

    std::ifstream file(employeesfile);
    
    while (file >> id) {
        file >> name >> pos >> worktime >> payment >> salary;
        if (pos == "Driver") {
            employees.push_back(new Driver(id, name,
                 DRIVER, worktime, payment, salary));
        }
        if (pos == "Cleaner") {
            employees.push_back(new Cleaner(id, name,
                 CLEANER, worktime, payment, salary));
        }
        if (pos == "ProjectManager") {
            employees.push_back(
                new ProjectManager(id, name,
                     PROJECTMANAGER, worktime, payment, *project));
        }
        if (pos == "Tester") {
            employees.push_back(new Tester(id, name,
                 TESTER, worktime, salary, payment, project));
        }
        if (pos == "Programmer") {
            employees.push_back(
                new Programmer(id, name,
                     PROGRAMMER, worktime, payment, salary, project));
        }
        if (pos == "TeamLeader") {
            employees.push_back(
                new TeamLeader(id, name,
                     TEAMLEADER, worktime, payment, salary, project));
        }
        if (pos == "SeniorManager") {
            employees.push_back(new SeniorManager(id, name,
                 SENIORMANAGER, worktime, payment, *project));
        }
        if (pos == "Engineer ") {
            employees.push_back(new Engineer(id, name,
                 ENGINEER, worktime, payment, salary, project));
        }
    }
    file.close();
    return employees;
}
